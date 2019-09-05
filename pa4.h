/*
 * Filename: pa4.h
 * Author: Sungyeol Oh
 * Userid: cs30ycb
 * Description: Defines constants for PA4 program
 * Date: 09/04/2017
 */

#ifndef PA4_H
#define PA4_H

#include <sys/stat.h> // for struct stat definition
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

// Number of chars in the fileInfo struct reserved for filenames
#define MAXLEN 256

// Number of pointers to add room for each time we realloc() children
#define CHILDREN_INCREMENT 8

// Boolean constants for general use
// Careful: in C true is any nonzero value, not always 1
#define TRUE 1
#define FALSE 0

struct fileInfo {
  // The path to the file
  char filename[MAXLEN];

  // Unix timestamp used to display a date and time for the file
  time_t time;

  // File size in bytes
  size_t size;

  // A bitfield representing access permissions
  mode_t mode;

  // The numeric ID of the file's owner
  uid_t uid;

  // The numeric ID of the file's group
  gid_t gid;

  // Boolean: 1 if this is a directory, 0 if it's a file
  int isDir;

  // Number of meaningful pointers in the children array
  int childrenSize;

  // Number of pointers allocated in the children array
  // Used to know when to realloc() the children array
  // childrenSize is always <= childrenCapacity
  int childrenCapacity;

  // Array of children (only relevant to directories)
  struct fileInfo ** children;
} ;

typedef enum {NAME, TIME} SortBy;

/* comparators */
int timeCompare (const void * p1, const void * p2); 
int timeCompareRev (const void * p1, const void * p2); 
int nameCompare (const void * p1, const void * p2); 
int nameCompareRev (const void * p1, const void * p2); 

/* functions used for printing */
void printFiles 
  (const struct fileInfo * fi, int showHidden, int longFormat, int indent); 
int getFileCount (const struct fileInfo * fi);  
void printPermissions (const mode_t mode); 
int isHidden(const char * filename);
void getFileInfo(struct fileInfo * fi, const char * filename);

/* building and freeing the tree */
struct fileInfo * buildFileTree (const char * filename, SortBy sortBy, int rev);
void freeFileTree(struct fileInfo * fi);

#endif /* PA4_H */
