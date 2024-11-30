<h1>LBYARCH C and Assembly Project</h1>
By San Buenaventura, Carlo & Villaflor, John Wayne S14
<hr>


GreyScaleImage Conversion Project (C and x86-64 Assembly):

This project demonstrates a program that converts uint8 based integers pixel values from a grayscaled image into single-precision floating-point values using a function implemented in x86-64 assembly. 
The implementation includes performance benchmarking and correctness verification.

<h3>Project Structure</h3>
<hr>
C Program (ConvertImageC.c):
Collects input, and creates dynamic array.
Measures execution time for benchmarking.

Assembly Function (ConvertImageAsm.asm):
Handles conversion of int pixels to float.
Handles division of input

<h3>Performance Analysis</h3>
<hr>
Runtimes were measured for different image sizes (height × width):

- 10 × 10
- 100 × 100
- 1000 × 1000
- The results for the average Runtimes are as follows:

Image Size | Avg x86-64 Runtime (ns) | Avg Total C Runtime (ns)
- 10×10 | 400 nanoseconds | 2364600 nanoseconds
- 100×100 | 46060 nanoseconds | 242228120 nanoseconds
- 1000×1000 | 3946720 nanoseconds | 1185548940 nanoseconds
<h3>Analysis:</h3>
<hr>

Each size were runned 30 times and computed to form the average execution time. In our Testing, its run time was consistently much faster as compared to the average run time for the C code. Additionally, upon running each scenario multiple times, we noticed that there was little to no fluctuation between each of the runtimes of each program. The runtimes would proportionally increase as we image size also did. An interesting observation we encountered was that the Runtime would significantly differ when running the program on better devices, highlighting the effects of having slightly different hardware to improve performance.
