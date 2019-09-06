
/*
 * Filename: testnameCompare.c
 * Author: Abdikhalik Ahmed
 * Userid: cs30s219ac@ucsd.edu
 * Description: Unit test program to test the function nameCompare().
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
 * Unit Test for nameeCompare()
 *
 * int nameCompare(const void* p1, const void* p2);
 * 
 *
 */
 void testnameCompare() { 



 char* fileName = "printFiles.c";//filename

 //create struct fileInfo
  struct fileInfo* file = (struct fileInfo*) malloc( sizeof(struct fileInfo));;

  getFileInfo(file, fileName);

 //create another file to compare with
  char* anotherFile = "main.c";

  struct fileInfo* file1 = (struct fileInfo*) malloc( sizeof(struct fileInfo));;
  getFileInfo(file1, anotherFile);
  

  //test 
  TEST( nameCompare(&file, &file1) == 1);//printFiles vs main.c

 
  
  //create another file to compare with
  char* filename = "getFileInfo.c";

  struct fileInfo* file3 = (struct fileInfo*) malloc( sizeof(struct fileInfo));;
  getFileInfo(file3,filename);

  //test
  TEST( nameCompare(&file3, &file1) == -1 );//main.c vs getFileInfo
  
  //free the files
  free(file);
  free(file1);
  free(file3);

}


int main() {
  fprintf( stderr, "Testing timeCompare...\n\n" );
  
   testnameCompare();
 
  fprintf( stderr, "\nDone running tests.\n" );
 
 return 0;
}


