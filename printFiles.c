
/*  
 * Filename: printFiles.c
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
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <unistd.h>
#include "pa4.h"
#include "pa4Strings.h"

#define BASE 10

/*
 * Function Name: printFiles()
 * Function Prototype:void printFiles(const struct fileInfo* fi,
 *                     const char* int showHidden, int showLongFmt, int indent);
 * Description: prints all the files    
 * Return Value: NONE
 */



void printFiles(const struct fileInfo* fi,  int showHidden,
                int showLongFmt, int indent) {   
    static int j = 0; 
    if(fi != NULL) { 
      
      int i =0;
     if(j ==0 && showLongFmt == 1)  {  
           //check if it is directory or not          
           fi->isDir == 1?printf("%c", 'd'):printf("%c", '-');
          
           //print relevant info of file 
           printPermissions(fi->mode);

           struct passwd* pasw = getpwuid(fi->uid);

           struct group* grp = getgrgid(fi->gid);
   

           struct tm* tm = localtime(&(fi->time));

           char* time = asctime(tm);

           printf(" %s", pasw->pw_name);

           printf(" %s ", grp->gr_name);

           printf("%5d", fi->size);

           for( int n = 3; n < 16; n++) {  
            
             printf("%c",time[n]); 

           }
           printf("%s", " " );
        j++; 
         
    }

    printf("%*s%s\n",indent,"", fi->filename);
    
   if( fi->childrenSize != 0) {
      
      while( i < fi->childrenSize) {       
         
          //check for flags
         if(showHidden == 0) {     
            //check if file is hiden
            if(isHidden(fi->children[i]->filename)){                
              i++;
              continue; 
            }               
         
         }
         //show all files an in long format
          if(  showLongFmt == 1) {   
        
           //check if it is directory or not          
           fi->children[i]->isDir == 1?printf("%c", 'd'):printf("%c", '-');
          
           //print relevant info of file 
           printPermissions(fi->children[i]->mode);

           struct passwd* pasw = getpwuid(fi->children[i]->uid);

           struct group* grp = getgrgid(fi->children[i]->gid);
   

           struct tm* tm = localtime(&(fi->children[i]->time));

           char* time = asctime(tm);

           printf(" %s", pasw->pw_name);

           printf(" %s ", grp->gr_name);

           printf("%5d", fi->children[i]->size);

           for( int k = 3; k< 16; k++) {  
            
             printf("%c",time[k]); 
           }
           printf("%s", " " );
           
        }
        j++;
        printFiles(fi->children[i], showHidden, showLongFmt, indent + 1);
    
        i++;
       } 
       
    }   
  }
}
