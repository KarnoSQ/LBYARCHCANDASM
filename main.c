// San Buenaventura, Carlo & Villaflor, John Wayne S16
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void imgCvtGrayInttoFloat(int* intImage, float* floatImage, int height, int width);

long calculate_nanoseconds(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec - start.tv_nsec);
}

int main() {
    int height, width;

    // Read image height and width
    printf("Enter the height and width of the image: ");
    scanf("%d %d", &height, &width);

    // Create Dynamic Array
    int* intImage = (int*)malloc(height * width * sizeof(int));

    // Read pixel values for the integer image
    printf("Enter the pixel values for the integer image (%d values):\n", height * width);
    for (int i = 0; i < height * width; i++) {
        scanf("%d", &intImage[i]);
    }

    // Measure the total runtime for the C program
    struct timespec c_start, c_end;
    clock_gettime(CLOCK_MONOTONIC, &c_start);

    // Allocate memory for output
    float* floatImage = (float*)malloc(height * width * sizeof(float));

    // Assembly Conversion
    // Measure the runtime for the x86-64 assembly function
    struct timespec asm_start, asm_end;
    clock_gettime(CLOCK_MONOTONIC, &asm_start);
    imgCvtGrayInttoFloat(intImage, floatImage, height, width);
    clock_gettime(CLOCK_MONOTONIC, &asm_end);

    // Print new converted values
    printf("Converted float image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%.2f ", floatImage[i * width + j]);
        }
        printf("\n");
    }

    clock_gettime(CLOCK_MONOTONIC, &c_end);

    // Compute runtimes in nanoseconds
    long asm_runtime_ns = calculate_nanoseconds(asm_start, asm_end);
    long c_runtime_ns = calculate_nanoseconds(c_start, c_end);

    // Print the runtimes in nanoseconds
    printf("x86-64 assembly function runtime: %ld nanoseconds\n", asm_runtime_ns);
    printf("Total C program runtime: %ld nanoseconds\n", c_runtime_ns);

    // Free allocated memory
    free(intImage);
    free(floatImage);

    return 0;
}