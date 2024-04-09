    .text
    .section .start,"ax",@progbits
    .align 3

    .global _start
    
_start:

    mflr       %r0
    std        %r0,0x10(%r1)
    stdu       %r1,-0x90(%r1)
    std        %r2,0x28(%r1)
    std        %r31,0x70(%r1)
    std        %r30,0x78(%r1)
    mr         %r31,%r3
    mr         %r30,%r0
    bl         get_toc
    mr         %r2,%r3
    mr         %r3,%r31
    mr         %r4,%r30
    bl         main
    nop
    ld         %r30,0x78(%r1)
    ld         %r31,0x70(%r1)
    ld         %r2,0x28(%r1)
    addi       %r1,%r1,0x90
    ld         %r0,0x10(%r1)
    mtlr       %r0
    blr
    


get_toc:

    mflr      %r0
    std       %r0, 0x10(%r1)
    lis       %r11, 0
    mr        %r11, %r11
    sldi      %r11, %r11, 32
    oris      %r11, %r11, 0xABC0
    mr        %r11, %r11
    bl        1f

1:
    lis       %r12, 0
    mr        %r12, %r12
    sldi      %r12, %r12, 32
    oris      %r12, %r12, __toc@ha
    ori       %r12, %r12, __toc@l
    subf      %r0, %r11, %r12
    lis       %r12, 0
    mr        %r12, %r12
    sldi      %r12, %r12, 32
    oris      %r12, %r12, 1b@ha
    ori       %r12, %r12, 1b@l
    subf      %r12, %r11, %r12
    mflr      %r11
    subf      %r12, %r12, %r11
    add       %r3, %r12, %r0
    ld        %r0, 0x10(%r1)
    mtlr      %r0
    blr
