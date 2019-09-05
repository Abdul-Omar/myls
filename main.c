/*  
 * Filename: create.c
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
#include <unistd.h>


/*
 * Function Name: main()
 * Function Prototype: main( int argc, char* argv[]);
 * Description: *     
 * Return Value: print bowtie pattern
 */
int main ( int argc, char* argv[]){
  
 
  int c = 0;//holds the return value of getOpts
  char* filename;
  int rev = 0;
  int longFmt = 0;
  int time = 0;
  int showHidden = 0;
  int count = 0;

  // process commandLine args
 while (( c = getopt(argc, argv, FLAGS)) != -1 ) { 
     
     
   switch(c) {  
       
       
      case FLAG_SHOWHIDDEN:

             showHidden = 1;
    
      case FLAG_COUNT:
                 
         count = 1;
         break;

      case FLAG_LONGFMT:

              longFmt = 1;

              break;

      case FLAG_REVERSE:

               rev = 1; 

              break;

      case FLAG_TIME:
            
             time = 1;

             break;

      case FLAG_FILENAME:

                filename = optarg;
               
               //check the file exists
               if(access(filename, F_OK) == -1) {                      
                    
                 fprintf(stderr,ERR_DNE, filename); 

                 return EXIT_FAILURE;                    
               }

               break;
      
      case FLAG_HELP:

               fprintf(stderr, STR_USAGE, argv[0]);
               
               return EXIT_FAILURE;
      
      case ':':

               
              filename = ".";
                break;

      case FLAG_UNKNOWN:
               
               fprintf(stderr, STR_USAGE, argv[0]);
               
               return EXIT_FAILURE;
               break;
      default:
               
               fprintf(stderr, STR_USAGE, argv[0]);
               
               return EXIT_FAILURE;


     }

  }

  //check for other errors
  if(optind < argc) { 
      
    fprintf(stderr,STR_EXTRA_ARG, argv[optind]);

    printf("%c",'\n');
    
    return EXIT_FAILURE;
  
  }

 SortBy criteria;//criteria to  sort the files by

//check time is used to sort or no
 if( time == 0) { 
     
     criteria = NAME;  
     
 }
 else { 
    
     criteria = TIME;
     
 }

 if (filename == NULL) {  
    
    filename = ".";
     
 }
 struct fileInfo* fi =  buildFileTree( filename,criteria, rev );

  //if file count was specified
  if( count  == 1)  {  
           
    int count = getFileCount(fi);   
   
    printf(STR_COUNT,filename, count);
      
   }

   printFiles(fi, showHidden, longFmt, 0);//print the files


   freeFileTree(fi);
}
