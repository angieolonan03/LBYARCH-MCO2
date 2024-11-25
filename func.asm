section .data
section .text
    bits 64
    default rel
    global dotProduct

dotProduct:
    ; Initialize registers and clear floating-point accumulators
    pxor XMM0, XMM0    ; Clear XMM0 (result accumulator)
    pxor XMM1, XMM1    ; Clear XMM1 (for loading vector A elements)
    pxor XMM2, XMM2    ; Clear XMM2 (for loading vector B elements)
    pxor XMM3, XMM3    ; Clear XMM3 (for intermediate products)
    pxor XMM4, XMM4    ; Clear XMM4 (sum accumulator)

    ; Start of loop
.loop_start:
    ; Load elements from vectors A and B
    movss XMM1, [RDX]    ; Load single float from vector A into XMM1
    movss XMM2, [R8]     ; Load single float from vector B into XMM2

    ; Perform element-wise multiplication
    vmulss XMM3, XMM1, XMM2  ; Multiply elements and store in XMM3

    ; Accumulate product into sum
    addss XMM4, XMM3          ; Add product to XMM4 (running sum)

    ; Increment pointers to the next elements in vectors
    add RDX, 4                ; Advance pointer for vector A
    add R8, 4                 ; Advance pointer for vector B

    ; Decrement the loop counter (RCX) and loop if not zero
    loop .loop_start

    ; Store the result in XMM0
    movss XMM0, XMM4          ; Move final result into XMM0 for return

    ; Return from function
    ret
