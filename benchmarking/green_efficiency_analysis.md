Green Efficiency Analysis
Measurement Methodology

The experiment was conducted using a C program written in the C programming language, compiled with strict compiler flags to ensure consistent behavior. Execution time was measured using the clock() function from the standard library. The program was divided into three phases: dataset construction (BUILD), dataset processing (PROCESS), and checksum computation (REDUCE). Each phase was timed separately by recording CPU clock values before and after execution, and converting the result into seconds using CLOCKS_PER_SEC.

The measurements were performed on the same machine under similar conditions to reduce environmental variability. The goal was to ensure that all comparisons reflected algorithmic behavior rather than external system load differences.

Observed Performance Differences

The recorded results show clear differences between the three phases. The PROCESS phase consistently took the most time, with values around ~0.09 seconds in most runs. The BUILD phase typically recorded lower execution times (~0.02 seconds), and the REDUCE phase was also relatively small (~0.02–0.03 seconds). The TOTAL execution time averaged approximately ~0.14 seconds.

These differences are expected due to the computational intensity of each phase. The PROCESS function performs multiple arithmetic operations per array element, making it significantly more expensive than simple dataset initialization or linear accumulation.

Relation Between Runtime and Energy Consumption

Runtime is directly related to CPU activity. When a program takes longer to execute, the CPU remains active for a longer period, which increases energy consumption. Although this experiment does not measure actual power usage in watts, execution time serves as a practical proxy for estimating energy impact.

The results demonstrate that more computationally expensive operations lead to longer runtime, which implies higher energy usage. Therefore, optimizing algorithms and reducing unnecessary computations can contribute to more energy-efficient software.

Limitations of the Experiment

This experiment has several limitations. First, it does not measure real energy consumption, only execution time. Second, results may vary slightly due to background system processes and CPU scheduling. Third, the dataset size is fixed, meaning scalability beyond 50,000 elements is not evaluated. Finally, the measurement tool (clock()) only captures CPU time and does not reflect multi-core or system-wide energy usage.

Practical Engineering Takeaway

This experiment demonstrates that performance analysis is essential in software development. Even simple programs can show significant differences in execution cost depending on how operations are structured. Identifying expensive sections of code allows developers to improve efficiency and reduce runtime.

Understanding how runtime correlates with computational workload helps engineers make better design decisions. Efficient algorithms not only improve speed but also contribute to reduced energy consumption, which is increasingly important in large-scale systems and cloud computing environments.
