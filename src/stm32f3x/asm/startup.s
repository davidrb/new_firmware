.syntax unified
.global reset_handler
.extern main

.text
.align
.thumb_func
reset_handler:
    ldr r1, =__vectors
    ldr r2, [r1]
    mov sp, r2

    bl __copy_data
    bl __zero_bss
    bl __init_heap
    bl __init
    bl system_setup
    bl main
    b .

halt: b halt

// copy the data section
__copy_data:
    ldr r0, =__rom_data_start
    ldr r1, =__ram_data_start
    ldr r2,=__ram_data_end

1:  cmp r1,r2
    it eq
    bxeq lr

    ldrb r4, [r0]
    strb r4, [r1]
    add r0, r0, #1
    add r1, r1, #1
    b 1b

// zero bss segment 
__zero_bss:
    ldr r0, =__bss_start
    ldr r1, =__bss_end
    mov r2, #0

1:  cmp r0, r1
    it eq
    bxeq lr

    strb r2, [r0]
    add r0, r0, #1
    b 1b

// call static constructors
__init:
    mov r6, lr
    ldr r4, =__init_array_start
    ldr r5, =__init_array_end

1:  cmp r4, r5 
    it eq
    bxeq r6
    
    ldr r2, [r4]
    blx r2
    add r4, r4, #4
    b 1b
