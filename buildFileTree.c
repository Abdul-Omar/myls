
/*  
 * Filename: buildFileTree.c
 * Author: Abdulkhaliq Omar
 * UserId: cs30s2019ac
 * Date:    9/5/2019
 * Sources of Help: None
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <getopt.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <grp.h>
#include <sysexits.h>
#include <time.h>
#include <pwd.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include "pa4.h"
#include "pa4Strings.h"

/*
 * Function Name: buildFileTree()
 * Function Prototype:struct fileInfo*  buildFileTree(const char* filename,
 *   Sortby sortby, int rev);
 * Description: this function builds the file tree of the directories and files 
 * Return Value: a struct fileInfo*, pointing to the top directory
 */



struct fileInfo*  buildFileTree(const char* filename, SortBy sortby, int rev){   
    
    struct stat filestat; 
    struct fileInfo* fi  = (struct fileInfo*)calloc (1, 
                                                     sizeof(struct fileInfo));
    
    //check for memory allocation error
    if( fi == NULL) {        
      fprintf(stderr, "memory error");        
      exit(EXIT_FAILURE); 
    }
   
   //fill the struct basic info
   getFileInfo(fi, filename);
   
   //try to open directory
   DIR* dir = opendir(filename);

   if(dir != NULL) { 
      
     fi->isDir = 1;//it is a dir      
   }

   else {  
      
     fi->isDir = 0;//not a dir    
   }
  
  struct dirent* dirEntry;//holds entry point of a directory
   
  if( dir != NULL)  { 
    //traverse the directory
    while( (dirEntry = readdir(dir)) != NULL) {  
    
         char currentPath [ BUFSIZ]; //holds the path
       
         //check name doesnot have '.' or '..'
         if( strcmp(dirEntry->d_name, ".") == 0 ||
            strcmp( dirEntry->d_name, "..") == 0) { 
          
           continue;//skip this file         
          }
     
          //copy this path into buffer
          snprintf(currentPath, BUFSIZ, FILE_CONCAT_FORMAT,
                               filename, dirEntry->d_name);
          //check children capacity not reached
         if(fi->childrenSize == fi->childrenCapacity) {  
             
            //add more space if capacity reached    
            fi->children =  realloc(fi->children,         
                (fi->childrenCapacity + CHILDREN_INCREMENT)*
                   sizeof(struct fileInfo*)); 
             fi->childrenCapacity = (fi->childrenCapacity + CHILDREN_INCREMENT);
            //check that realloc worked
            if (  fi->children == NULL) {                   
              perror(__func__);
              free( fi->children);
              free(fi);
              return NULL;
             }  
          }
       
          //recursively build the tree
          fi->children[fi->childrenSize] =
             buildFileTree(currentPath, sortby, rev);          
       
         fi->childrenSize += 1;//increment num of children  
     } 
  }
 
   closedir(dir);//close the directory  

   //if no reverse comparison is wanted
   if(rev == 0) {  
          
     //sort by name   
     if( sortby == NAME) {             
           
       qsort( fi->children, fi->childrenSize,
              sizeof(struct fileInfo*), nameCompare); 
      }
      
      //sort by Time
      else { 
          
         qsort( fi->children, fi->childrenSize,
               sizeof(struct fileInfo*), timeCompare); 
       }          
          
     }
     //use reverse comparison
     else {

       //reverse compare names
       if ( sortby == NAME) { 
         
         qsort(fi->children, fi->childrenSize,
             sizeof(struct fileInfo*), nameCompareRev);
       }
       //sort by time
       else {           
         
         qsort(fi->children, fi->childrenSize, 
             sizeof(struct fileInfo*), timeCompareRev);          
       }       
    }        
   
   return fi;
} 
    
