
/*
 * Filename: timeCompare.s
 * Author: Abdulkhaliq Omar
 * Userid: cse30s219ac
 * Description: defines the timeCompare funtion that is passed in as
 *              parameter for qsort() function used in the PA4 program.
 * Date: 9/5/2019
 */

.syntax unified

.equ FP_OFFSET, 4
.equ PARAM_SPACE, 16
.equ P1_OFFSET, -8
.equ P2_OFFSET, -12

.text
.align 2
.global timeCompare

/*
 * Function name: timeCompare()
 * Function prototype: timeCompare(const void*p1, const void* p2);
 * Description: this functions compares times of two files
 * Parameters: p1, the first file, p2-the second file
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: 0-if equal, -1-first is smaller, 1-second is smaller
 * Registers Used: r0-parameters, r1, parameters( and basic operations)
 */


timeCompare:
   
   
   @ Save caller's registers on the stack
    push {fp, lr}

    add fp, sp, FP_OFFSET

    sub sp, sp, PARAM_SPACE

    str r0, [fp, P1_OFFSET]

    str r1, [fp, P2_OFFSET]



    ldr r0, [fp, P1_OFFSET]
    
    ldr r0, [r0]
   
    ldr r2, =offset_time         @ get time offset
    
    ldr r2, [r2]                 @get actual value of ofset

    
    add r0, r0, r2               @get address of time

    
    ldr r0,[r0]                  @get actual value of time
    
    ldr r1, [fp, P2_OFFSET]
    ldr r1, [r1] 
    ldr r2, =offset_time 
    
    ldr r2, [r2]                 @get actual value of offset
    
    add r1, r1, r2               @get address of time

    ldr r1, [r1]                 @ get actual value of time
    
    
    

    cmp r0, r1                   @ compare the two times

    bne if

    mov r0, 0

    b end

if:
     cmp r0, r1                  @compare the two times 
  
     blt  negative

positive:

       mov r0, 1
       
       b end


negative:


     mov r0, -1
     b end

end:

     sub sp, fp, FP_OFFSET

     pop {fp, pc}




