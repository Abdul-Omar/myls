/*
 * Filename: nameCompare.s
 * Author: Abdikhalik Ahmed
 * Userid: cs30s219ac@ucsd.edu
 * Description: defines the nameCompare funtion that is passed in as
 *              parameter for qsort() function used in the PA4 program.
 * Date: 9/5/2019
 * Sources of Help: NONE
 */

.syntax unified

.equ FP_OFFSET, 4
.equ PARAM_SPACE, 16
.equ P1_OFFSET, -8
.equ P2_OFFSET, -12

.text
.align 2
.global nameCompare

/*
 * Function name: nameCompare()
 * Function prototype: nameeCompare(const void*p1, const void* p2);
 * Description: this function comparesnames of two files
 * Parameters: p1, the first file, p2-the second file
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: 0-if equal, -1-first is smaller, 1-second is smaller
 * Registers Used: r0-parameters, r1, parameters( and basic operations)
 */

nameCompare:
   
   
    @ Save caller's registers on the stack
    push {fp, lr}

    @ Translation #1: Assembly to Machine Instruction: ADD
    add fp, sp, FP_OFFSET
    @ .word 0xE28DB004 

    sub sp, sp, PARAM_SPACE

    str r0, [fp, P1_OFFSET]

    @ Translation #2: Assembly to Machine Instruction: STR
    str r1, [fp, P2_OFFSET]
    @ .word 0xE50B100C

if:
    @ Call strcmp on two names

    ldr r0, [fp, P1_OFFSET]

    ldr r0, [r0]                 @ get 1st name into r0
    @ Translation #3: Assembly to Machine Instruction: LDR
    ldr r1, [fp, P2_OFFSET]
    @ .word 0xE51B100C 
   
    ldr r1, [r1]                 @ get 2nd name into r1
    bl strcmp

    @ strcmp returned value < 0, first < second
    cmp r0, 0
    @ Translation #4: Assembly to Machine Instruction: BGE
    bge else_if
    @ .word 0xAA000003 

    @ return -1
    mov r0, -1
    b end_if

else_if:
    @ Call strcmp on two names
    ldr r0, [fp, P1_OFFSET]
    ldr r0, [r0]                 @ get 1st name into r0
    ldr r1, [fp, P2_OFFSET]
    ldr r1, [r1]                 @ get 2nd name into r1
    bl strcmp

    @ strcmp returned value > 0, first > second
    cmp r0, 0

    @ Translation #5: Assembly to Machine Instruction: BLE
    ble else
    @ .word 0xDA000001

    @ return 1
    mov r0, 1
    b end_if

else:
    @ Else, equal, so return 0
    mov r0, 0

end_if:
    @ Translation #6: Assembly to Machine Instruction: SUB
    sub sp, fp, FP_OFFSET
    @ .word 0xE24BD004

    @ Restore caller's registers
    pop {fp, pc}
