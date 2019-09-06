/*
 * Filename: testtimeCompare.c
 * Author: Abdikhalik Ahmed
 * Userid: cs30s219ac@ucsd.edu
 * Description: Unit test program to test the function timeCompare().
 * Date: 8/29/2019
 * Sources of Help: NONE
 */

#include <string.h>
#include <stdlib.h>

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa4.h"
#include "pa4Strings.h"
#include "getFileInfo.c"

/*
 * Unit Test for timeCompare()
 *
 * int timeCompare(const void* p1, const void* p2);
 * 
 *
 */
 void testtimeCompare() { 


  //create  a file to start
  char* fileName = "printFiles.c";
 //allocate space for fileInfo struct
  struct fileInfo* file = (struct fileInfo*) malloc( sizeof(struct fileInfo));;
  //fill the file
  getFileInfo(file, fileName);
 
  //create another file to compare with
  char* anotherFile = "main.c";

  struct fileInfo* file1 = (struct fileInfo*) malloc( sizeof(struct fileInfo));;
  getFileInfo(file1, anotherFile);

  //test
  TEST( timeCompare(&file, &file1) == -1);//printFiles vs main.c
  
  //create a third file to compare with
  char* filename = "getFileInfo.c";
  //creat struct
  struct fileInfo* file3 = (struct fileInfo*) malloc( sizeof(struct fileInfo));;
  getFileInfo(file3,filename);

  //test
  TEST( timeCompare(&file1, &file3) == 1 );//main.c vs getFileInfo

  //free memory
  free(file);
  free(file1);
  free(file3);
}


int main() {
  fprintf( stderr, "Testing timeCompare...\n\n" );
  
   testtimeCompare();
 
  fprintf( stderr, "\nDone running tests.\n" );
 
 return 0;
}


