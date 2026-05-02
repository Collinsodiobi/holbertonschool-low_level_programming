# Valgrind & Memory Analysis

This document analyzes memory behavior of four C programs using Valgrind and explains each issue in terms of stack/heap lifetime, ownership, and pointer behavior.

---

## 1. stack_example

### Valgrind Result
- No errors detected
- No memory leaks

### Memory Analysis
This program uses stack memory through recursive function calls. Each call creates a new stack frame containing local variables such as `local_int`, `local_buf`, and `marker`.

Each stack frame has:
- Independent memory addresses
- Independent variable instances

When a function returns:
- Its stack frame is automatically destroyed
- No manual deallocation is required

### Key Insight
Stack memory is automatically managed. Since there is no heap allocation, there are no leaks or invalid accesses.

---

## 2. heap_example

### Valgrind Result
- definitely lost: 6 bytes in 1 blocks

### Memory Analysis
This program uses heap allocation via `malloc`. Each object contains dynamically allocated memory.

One allocated block is not freed before program termination.

### Root Cause
- Memory allocated on heap
- Pointer to one block was lost (lost ownership)
- No `free()` call was performed for that block

### Key Insight
Heap memory must be explicitly freed. If a pointer to it is lost, it becomes unreachable → memory leak.

---

## 3. aliasing_example

### Valgrind Result
- Invalid read of size 4
- Invalid write of size 4

### Memory Analysis
Pointers `a` and `b` point to the same heap memory (aliasing).

After `free(a)`:
- The memory is released
- `b` becomes a dangling pointer

Any access through `b` is use-after-free.

### Key Insight
Aliasing + free creates unsafe dangling pointers and undefined behavior.

---

## 4. crash_example

### Valgrind Result
- Invalid write at address 0x0
- Segmentation fault

### Memory Analysis
The program dereferences a NULL pointer.

Address `0x0` is invalid memory, so any access causes a crash.

### Key Insight
NULL pointer dereference leads to segmentation fault immediately.

---

## AI Correction Example

AI initially suggested that heap_example had no real leak because the program terminates cleanly.

This is incorrect.

### Correction:
Valgrind explicitly reports:
- "definitely lost: 6 bytes"

This means:
- The heap block is not reachable from any valid pointer
- The pointer to that memory was lost before program termination
- The memory cannot be freed anymore

### Explanation:
A memory leak is determined by **reachability**, not program exit status. Even if a program exits normally, memory is still leaked if it is unreachable.

### Conclusion:
Valgrind detects leaks based on memory reachability, not program termination.
