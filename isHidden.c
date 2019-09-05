/*
 * Filename: isHidden.c
 * Author: David A and Kevin C
 * Userid: cs30ycb
 * Description: Defines the isHidden function for the PA4 program.
 * Date: 08/29/2017
 * Sources of help: Given file
 */

#include "pa4.h"

/* return true if file is hidden */
int isHidden(const char * filename){
  if (!filename) return FALSE;
  int j = -1;
  int i;
  for (i=0; filename[i]; i++) if (filename[i]=='/') j = i;
  if ( filename[j+1]!='.' ) return FALSE;
  for (j++; filename[j]; j++) if (filename[j]!='.') return TRUE;
  return FALSE;
}
