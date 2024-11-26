# LBYARCH-MCO2
## Overview
This project is submitted as part of the requirements for LBYARCH, under the supervision of Sir Jonathan Cempron. The program implements a dot product computation using both C and x86-64 assembly. The primary objective is to compare the performance of these two implementations in terms of execution time and validate the correctness of the results.

## Instructions to Run the Program
### Prerequisites
Compiler and Assembler:
  
C compiler with C99 standard support (GCC).  
NASM assembler for compiling the assembly code.  
Operating System: Windows  
Hardware Requirements: x86-64 compatible processor.  

## Compilation Steps (done in cmd):
nasm -f win64 func.asm  
gcc -std=c99 -c main.c -o main.obj -m64  
gcc main.obj func.obj -o main.exe -m64  
.\main  

## Output

## Comparative Analysis

The performance of the dot product was analyzed using different vector sizes. Below is a summary of the results:

| Vector Size | C Execution Time (s) | Assembly Execution Time (s) | Speedup | Similarity |
|-------------|-----------------------|-----------------------------|---------|------------|
| 2^20        | 0.003367              | 0.000733                    | 4.59x   | 100.00%    |
| 2^24        | 0.052067              | 0.011267                    | 4.62x   | 100.00%    |
| 2^28        | 0.825967              | 0.182767                    | 4.52x   | 100.00%    |

### Observations
Correctness: 
Results from both implementations are identical across all tests, with 100% similarity.
Performance:
The assembly implementation consistently outperforms the C implementation, being approximately 4.5 times faster on average.
The speedup is attributed to the optimized low-level operations in assembly.


## Conclusion
This project demonstrates the efficiency of x86-64 assembly in computationally intensive tasks such as dot product calculations. While C offers simplicity and portability, assembly provides superior performance, making it suitable for high-performance applications.
