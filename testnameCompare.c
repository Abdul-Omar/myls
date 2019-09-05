
/*
 * Filename: testnameCompare.c
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
 * Unit Test for nameeCompare()
 *
 * int nameCompare(const void* p1, const void* p2);
 * 
 *
 */
 void testnameCompare() { 



 char* fileName = "printFiles.c";

  struct fileInfo file;
  


  getFileInfo(&file, fileName);

 char* anotherFile = "main.c";

  struct fileInfo file1;

   getFileInfo(&file1, anotherFile);

  //TEST( nameCompare(&file, &file1) == 1 );

 

  
 char* filename = "testtimeCompare.c";

  struct fileInfo file3;

  getFileInfo(&file3,filename);


 TEST( nameCompare(&file1, &file1) == 0);
}


int main() {
  fprintf( stderr, "Testing timeCompare...\n\n" );
  
   testnameCompare();
 
  fprintf( stderr, "\nDone running tests.\n" );
 
 return 0;
}


