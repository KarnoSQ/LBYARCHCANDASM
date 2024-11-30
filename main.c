// San Buenaventura, Carlo & Villaflor, John Wayne S16
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void imgCvtGrayInttoFloat(int* intImage, float* floatImage, int height, int width);


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
    clock_t c_start, c_end;
    c_start = clock();
    // Allocate memory for output
    float* floatImage = (float*)malloc(height * width * sizeof(float));

    // Assembly Conversion
    // Measure the runtime for the x86-64 assembly function
    clock_t asm_start, asm_end;
    asm_start = clock();
    imgCvtGrayInttoFloat(intImage, floatImage, height, width);
    asm_end = clock();

    // Print new converted values
    printf("Converted float image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%.2f ", floatImage[i * width + j]);
        }
        printf("\n");
    }

    c_end = clock();

    // Compute runtimes in nanoseconds
    long asm_runtime_ns = (long)((asm_end - asm_start) * 1000000000.0 / CLOCKS_PER_SEC);
    long c_runtime_ns = (long)((c_end - c_start) * 1000000000.0 / CLOCKS_PER_SEC);

    // Print the runtimes in nanoseconds
    printf("x86-64 assembly function runtime: %ld nanoseconds\n", asm_runtime_ns);
    printf("Total C program runtime: %ld nanoseconds\n", c_runtime_ns);

    // Free allocated memory
    free(intImage);
    free(floatImage);

    return 0;
}