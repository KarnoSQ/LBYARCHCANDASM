; San Buenaventura, Carlo & Villaflor, John Wayne S16
section .text
bits 64
default rel
global imgCvtGrayInttoFloat

imgCvtGrayInttoFloat:
    push rbp
    mov rbp, rsp
    push rbx

    mov rdi, rcx    ; intImage pointer
    mov rsi, rdx    ; floatImage pointer
    mov edx, r8d    ; height
    mov ecx, r9d    ; width

    ; Total number of pixels
    imul edx, ecx          ; edx = height * width

    mov eax, 255           ; Load 255 as an integer
    cvtsi2ss xmm1, eax     ; Convert 255 to a float

    ; Initialize loop index
    xor ebx, ebx           ; Index (i)

convert_loop:
    ; Check if all pixels are processed
    cmp ebx, edx
    jge end_loop           ; Exit loop if i >= total_pixels

    ; Load integer pixel value into xmm0
    mov eax, dword [rdi + rbx * 4] ; Load intImage[i]
    cvtsi2ss xmm0, eax             ; Convert integer to float

    ; Perform division: f = i / 255
    divss xmm0, xmm1              

    ; Store result in floatImage
    movss dword [rsi + rbx * 4], xmm0

    inc ebx
    jmp convert_loop

end_loop:
    pop rbx
    mov rsp, rbp
    pop rbp
    ret
