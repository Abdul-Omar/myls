
/** Filename: freeFileTree.c
 * Author: Abdikhalik Ahmed
 * UserId: cs30s2019ac
 * Date:    8/29/2019
 * Sources of Help: None
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <getopt.h>
#include "pa4.h"
#include "pa4Strings.h"

#define BASE 10

/*
 * Function Name: freeFileTree()
 * Function Prototype:int freeFileTree(const struct fileInfo* fi);
 * Description: frees the dynamically allocated memory for the file tree   
 * Return Value: NONE
 */
void freeFileTree( struct fileInfo * fi) {   
  
  //base case
   if(fi != NULL) {      
       return;       
   }
  
   int i = 0;
  
   while( i < fi->childrenSize) {       

     freeFileTree(fi->children[i]);//free its children
     i++;
  }    
        
  free(fi);//free fi 
} 

