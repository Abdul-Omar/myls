/*
 * Filename: getFileCount.s
 * Author: Abdikhalik Ahmed
 * Userid: cse30s219ac
 * Description: this function counts the number of files in file tree
 * Date: 9/5/2019
 * Sources of Help: NONE
 */

.syntax unified

.equ FP_OFFSET, 4
.equ PARAM_SPACE, 16
.equ P1_OFFSET, -8
.equ COUNT_OFFSET, -12
.equ I_OFFSET, -16
.equ SIZE_OFFSET, -20

.text
.align 2
.global getFileCount

/*
 * Function name: getFileCount()
 * Function prototype:getFileCount(const struct fileInfo* fi);
 * Description: this function returns the totoal number of files in the tree
 * Parameters: struct fileInfo* fi, the root of the file tree
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: returns totoal number of files
 * Registers Used: r0 -r3 parameters( and basic operations)
 */
 
 getFileCount:
   
   
   @ Save caller's registers on the stack
   
     push {fp, lr}

     add fp, sp, FP_OFFSET

     sub sp, sp, PARAM_SPACE

    
     str r0, [fp, P1_OFFSET]

     mov r1, 1

     str r1, [fp, COUNT_OFFSET]          @store counter
   
   

if:
   
     ldr r0, [fp, P1_OFFSET]            @ get struct pointer
   
     cmp r0, 0                          @ is fi == NULL?

     beq return
     
     mov r2, 0                            @Iinitialize i                           

     str r2, [fp, I_OFFSET]               @store i


while:

    ldr r1, [fp, I_OFFSET]              @ get value of i

    ldr r2, =offset_childrenSize        @ load children offset

    ldr r2, [r2]                       @get value of childrensize offset
    
    add r0, r0, r2                     @get address of childrensie

    ldr r0, [r0]                      @ get actual value of children size;
    
    str r0, [fp, SIZE_OFFSET]         @ store size
   
    ldr r0, [fp, SIZE_OFFSET]
   
    cmp r1, r0                         @ is i == childrensize

    bge return



loop:

    ldr r0, [fp, P1_OFFSET]              @ load fi pointer


    ldr r2, =offset_children            @ get offset of children

    ldr r2, [r2]                        @ get actual value of offset
 
    add r0, r0, r2                      @get address of children

    ldr r3, [fp, I_OFFSET]             @get current value of i
     
    mov r2, 4

    mul r3, r3, r2                     @ scale index
    
    add r0, r0, r3                     @get address of children[i]

    bl getFileCount
   
    ldr r1, [fp, COUNT_OFFSET]         @ get count variable
   
    add r1, r1, r0                     @ count+= getFileCount(fi->children[i]

    str r1, [fp, COUNT_OFFSET]         @ Store count

    ldr r3, [fp, I_OFFSET]             @ get value of i

    add r3, r3, 1                      @ i++

    str r3, [fp, I_OFFSET]

    ldr r3, [fp, I_OFFSET]
  
    ldr r1, [fp, SIZE_OFFSET]

    
    cmp r3, r1                        @ is i == children size

    blt loop


   
return:

   ldr r0, [fp, COUNT_OFFSET]
  
end:

     sub sp, fp, FP_OFFSET

     pop {fp, pc}



