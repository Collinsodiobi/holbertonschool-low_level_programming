Benchmarking Report

This experiment measures execution time of a C program using clock() from the C standard library.

The program is divided into three phases: BUILD, PROCESS, and REDUCE. Each phase was timed independently, along with total execution time.

Results show that the PROCESS phase takes the most time because it performs multiple arithmetic operations on a large dataset. The BUILD and REDUCE phases are faster because they involve simpler computations.

The total execution time is consistent with the sum of all phases, confirming correct instrumentation.

This experiment demonstrates how CPU time can be measured in C and how performance bottlenecks can be identified in programs.
