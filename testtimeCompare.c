/*
 * Filename: testtimeCompare.c
 * Author: Abdikhalik Ahmed
 * Userid: cs30s219ac@ucsd.edu
 * Description: Unit test program to test the function writeTables().
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



 char* fileName = "printFiles.c";

  struct fileInfo* file = (struct fileInfo*) malloc( sizeof(struct fileInfo));;

  getFileInfo(file, fileName);

 char* anotherFile = "main.c";


  struct fileInfo* file1 = (struct fileInfo*) malloc( sizeof(struct fileInfo));;
  getFileInfo(file1, anotherFile);


  TEST( timeCompare(file, file1) == -1);//printFiles vs main.c

 

  
 char* filename = "getFileInfo.c";


  struct fileInfo* file3 = (struct fileInfo*) malloc( sizeof(struct fileInfo));;
  getFileInfo(file3,filename);


  TEST( timeCompare(file1, file3) == 1 );//main.c vs getFileInfo
}


int main() {
  fprintf( stderr, "Testing timeCompare...\n\n" );
  
   testtimeCompare();
 
  fprintf( stderr, "\nDone running tests.\n" );
 
 return 0;
}


