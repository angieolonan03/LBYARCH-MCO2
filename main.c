#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>

// Constants
#define ITERATIONS 30
#define MAX_VALUE 100.0f

// Assembly Dot Product Function
extern float dotProduct(int size, float* vec1, float* vec2);

// C Dot Product Function
float calculateDotProduct(int size, float* vec1, float* vec2) {
    float result = 0.0f;

    for (int i = 0; i < size; i++) {
        result += vec1[i] * vec2[i];
    }

    return result;
}

// Generate Random Values for a Vector
void populateRandomVector(int size, float* vector) {
    int index = 0;
    int power = 1;

    for (int i = 0; i < size; i++) {
        vector[i] = ((float)rand() / RAND_MAX) * MAX_VALUE;
        vector[i] = ((int)(vector[i] * MAX_VALUE)) / MAX_VALUE;

        if (rand() % 2 == 0) {
            vector[i] *= -1;
        }

        if (i == power - 1) {
            printf("%i\n", power);
            index++;
            power *= 2;
        }
    }
}

// Calculate Average Time
double calculateAverage(double* timeData) {
    double sum = 0.0;

    for (int i = 0; i < ITERATIONS; i++) {
        sum += timeData[i];
    }

    return sum / ITERATIONS;
}

// Main Program
int main() {
    int size = 0;
    float* vectorA = (float*)malloc((int)pow(2, 28) * sizeof(float));
    float* vectorB = (float*)malloc((int)pow(2, 28) * sizeof(float));
    float cResult = 0.0f;
    float asmResult = 0.0f;

    double cTimes[ITERATIONS];
    double asmTimes[ITERATIONS];
    double cAvgTime, asmAvgTime;

    srand((unsigned int)time(NULL));
    printf("Initializing Vector A:\n");
    populateRandomVector((int)pow(2, 28), vectorA);
    printf("Vector A Completed.\n\n");
    printf("Initializing Vector B:\n");
    populateRandomVector((int)pow(2, 28), vectorB);
    printf("Vector B Completed.\n\n");

    printf("\n======================================================\n");
    printf("Program Execution Begins: Vector Size = 2^20 \n");
    printf("======================================================\n");
    size = (int)pow(2, 20);
    printf("Vector Size: 2^20 = %d\n\n", size);

    // Measure C Function Performance
    printf("C Dot Product Performance:\n");
    for (int i = 0; i < ITERATIONS; i++) {
        clock_t start = clock();
        cResult = calculateDotProduct(size, vectorA, vectorB);
        clock_t end = clock() - start;
        cTimes[i] = ((double)end) / CLOCKS_PER_SEC;
    }
    cAvgTime = calculateAverage(cTimes);
    printf("Result (Base 10): %f\n", cResult);
    printf("Result (Hexadecimal): %x\n", *(unsigned int*)&cResult);
    printf("Average Execution Time: %lf seconds\n\n", cAvgTime);

    // Measure Assembly Function Performance
    printf("Assembly Dot Product Performance:\n");
    for (int i = 0; i < ITERATIONS; i++) {
        clock_t start = clock();
        asmResult = dotProduct(size, vectorA, vectorB);
        clock_t end = clock() - start;
        asmTimes[i] = ((double)end) / CLOCKS_PER_SEC;
    }
    asmAvgTime = calculateAverage(asmTimes);
    printf("Result (Base 10): %f\n", asmResult);
    printf("Result (Hexadecimal): %x\n", *(unsigned int*)&asmResult);
    printf("Average Execution Time: %lf seconds\n\n", asmAvgTime);

    // Compare Results
    printf("Comparison Results:\n");
    printf("Similarity: %.2f%%\n", (cResult / asmResult) * 100);
    double timeDifference = cAvgTime - asmAvgTime;
    if (timeDifference > 0) {
        printf("Assembly is faster by %.2lf times\n", cAvgTime / asmAvgTime);
    } else {
        printf("C is faster by %.2lf times\n", asmAvgTime / cAvgTime);
    }

    //Program 2
    printf("\n======================================================\n");
    printf("Program Execution Begins: Vector Size = 2^24 \n");
    printf("======================================================\n");
    size = (int)pow(2, 24);
    printf("Vector Size: 2^24 = %d\n\n", size);

    // Measure C Function Performance
    printf("C Dot Product Performance:\n");
    for (int i = 0; i < ITERATIONS; i++) {
        clock_t start = clock();
        cResult = calculateDotProduct(size, vectorA, vectorB);
        clock_t end = clock() - start;
        cTimes[i] = ((double)end) / CLOCKS_PER_SEC;
    }
    cAvgTime = calculateAverage(cTimes);
    printf("Result (Base 10): %f\n", cResult);
    printf("Result (Hexadecimal): %x\n", *(unsigned int*)&cResult);
    printf("Average Execution Time: %lf seconds\n\n", cAvgTime);

    // Measure Assembly Function Performance
    printf("Assembly Dot Product Performance:\n");
    for (int i = 0; i < ITERATIONS; i++) {
        clock_t start = clock();
        asmResult = dotProduct(size, vectorA, vectorB);
        clock_t end = clock() - start;
        asmTimes[i] = ((double)end) / CLOCKS_PER_SEC;
    }
    asmAvgTime = calculateAverage(asmTimes);
    printf("Result (Base 10): %f\n", asmResult);
    printf("Result (Hexadecimal): %x\n", *(unsigned int*)&asmResult);
    printf("Average Execution Time: %lf seconds\n\n", asmAvgTime);

    // Compare Results
    printf("Comparison Results:\n");
    printf("Similarity: %.2f%%\n", (cResult / asmResult) * 100);
    double timeDifference = cAvgTime - asmAvgTime;
    if (timeDifference > 0) {
        printf("Assembly is faster by %.2lf times\n", cAvgTime / asmAvgTime);
    } else {
        printf("C is faster by %.2lf times\n", asmAvgTime / cAvgTime);
    }

    //Program 3
    printf("\n======================================================\n");
    printf("Program Execution Begins: Vector Size = 2^28 \n");
    printf("======================================================\n");
    size = (int)pow(2, 28);
    printf("Vector Size: 2^28 = %d\n\n", size);

    // Measure C Function Performance
    printf("C Dot Product Performance:\n");
    for (int i = 0; i < ITERATIONS; i++) {
        clock_t start = clock();
        cResult = calculateDotProduct(size, vectorA, vectorB);
        clock_t end = clock() - start;
        cTimes[i] = ((double)end) / CLOCKS_PER_SEC;
    }
    cAvgTime = calculateAverage(cTimes);
    printf("Result (Base 10): %f\n", cResult);
    printf("Result (Hexadecimal): %x\n", *(unsigned int*)&cResult);
    printf("Average Execution Time: %lf seconds\n\n", cAvgTime);

    // Measure Assembly Function Performance
    printf("Assembly Dot Product Performance:\n");
    for (int i = 0; i < ITERATIONS; i++) {
        clock_t start = clock();
        asmResult = dotProduct(size, vectorA, vectorB);
        clock_t end = clock() - start;
        asmTimes[i] = ((double)end) / CLOCKS_PER_SEC;
    }
    asmAvgTime = calculateAverage(asmTimes);
    printf("Result (Base 10): %f\n", asmResult);
    printf("Result (Hexadecimal): %x\n", *(unsigned int*)&asmResult);
    printf("Average Execution Time: %lf seconds\n\n", asmAvgTime);

    // Compare Results
    printf("Comparison Results:\n");
    printf("Similarity: %.2f%%\n", (cResult / asmResult) * 100);
    double timeDifference = cAvgTime - asmAvgTime;
    if (timeDifference > 0) {
        printf("Assembly is faster by %.2lf times\n", cAvgTime / asmAvgTime);
    } else {
        printf("C is faster by %.2lf times\n", asmAvgTime / cAvgTime);
    }

    // Free Memory
    free(vectorA);
    free(vectorB);

    return 0;
}
