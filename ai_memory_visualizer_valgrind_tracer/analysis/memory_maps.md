# Memory Maps Analysis

## 1. Stack Behavior (stack_example)

Each recursive function call creates a new stack frame.
Each frame contains independent local variables stored in stack memory.

The printed addresses show that each call has different memory locations,
confirming separate stack frames.

When a function returns, its stack frame is destroyed automatically.

## 2. Variable Lifetime

Local variables exist only during the execution of their function call.
After the function returns, those memory addresses are no longer valid.

No manual deallocation is needed because stack memory is automatically managed.

## 3. Pointer Behavior

p_local points to local_int in the current stack frame.

After the function returns, p_local becomes a dangling pointer because it
still holds an address of memory that has been freed (stack frame destroyed).

## 4. AI / Common Mistake Correction

Incorrect assumption:
All recursive calls reuse the same memory for local variables.

Correction:
Each recursive call creates a new stack frame with its own independent
memory region. Variables are not shared across calls.
## 5. Heap Behavior (heap_example)

Heap memory is allocated using malloc and remains valid until explicitly freed.

In this program, both alice and bob are allocated separately on the heap.

Each struct contains its own dynamically allocated name field,
which is also stored independently in heap memory.

Memory is not automatically released, meaning failure to call free
would result in a memory leak.

Heap addresses differ for each allocation, confirming independent memory blocks.
## 6. Pointer Aliasing and Use-After-Free (aliasing_example)

Both pointers a and b reference the same heap memory block,
demonstrating pointer aliasing.

Modifying data through either pointer affects the same memory.

After free(a), the heap memory is released, but b still holds
the old address, becoming a dangling pointer.

Accessing b after free results in undefined behavior, including
reading garbage values and writing to invalid memory.

This is a classic use-after-free bug that can lead to memory corruption
or program crashes.
## 7. Crash Analysis (crash_example)

The program crashes due to a deterministic NULL pointer dereference.

When the input n = 0, the function returns or produces a NULL pointer.

The program then attempts to access memory through this NULL pointer.

Since address 0 is not valid in user space, the operating system
raises a segmentation fault.

This is a predictable crash caused by invalid memory access, not random behavior.

The full causal chain is:
input n = 0 → NULL pointer returned → dereference of NULL → segmentation fault.
