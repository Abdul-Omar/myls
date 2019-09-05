
/*  
 * Filename: getFileInfo.c
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
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <grp.h>
#include <sysexits.h>
#include <time.h>
#include <pwd.h>
#include <strings.h>
#include <unistd.h>
#include "pa4.h"
#include "pa4Strings.h"



/*
 * Function Name: getFileInfo()
 * Function Prototype: getFileInfo( struct fileInfo* fi, const char*
 * Description: fills struct with info from file 
 * Return: NONE   
 */



void getFileInfo(struct fileInfo* fi, const char* filename) { 
    
   int len = strlen(filename);//get length of file

   struct stat sb;//holds the file info
   
   //check for errors
   if ( lstat( filename, &sb) == -1) { 
          
     fprintf(stderr, "error");

     exit(EXIT_FAILURE);     
       
   }

  int i;
  //copy filename into struct's filename
  for( i = 0; i < (len ); i++) {  
     
    fi->filename[i] = filename[i];     
  }
    
  fi-> time = sb.st_mtime;//get modification time
  fi->size = sb.st_size;//size of file
  fi->mode = sb.st_mode;//mode of file
  fi->uid = sb.st_uid;//userid
  fi->gid = sb.st_gid;//group id

} 
    
