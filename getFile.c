/** Filename: getFileCount.c
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
 * Function Name: getFileCount()
 * Function Prototype:int getFileCount(const struct fileInfo* fi);
 * Description: returns the number of files in the file tree    
 * Return Value: number of files and directories
 */

int getFileCount(const struct fileInfo* fi) {   
   
    int count = 1;//start at the root,count num of files
    
    if(fi != NULL) { 
     
      int i =0;
      while( i < fi->childrenSize) {       
       
        
        count += getFileCount(fi->children[i]);//recurse
        i++;

      }   
   
   } 
   return count;    
} 

