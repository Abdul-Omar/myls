
/*  
 * Filename: printPermissions.c
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
 * Function Name:printPermissions()
 * Function Prototype: printPermissions(const mode_t mode);
 * Description: * prin tthe permissions of a file    
 * Return Value: NONE
 */
void printPermissions(const mode_t mode) { 
    
 //print user permission
 printf((mode & S_IRUSR) ? "r": "-");

 printf((mode & S_IWUSR) ? "w": "-");

 printf((mode & S_IXUSR) ? "x": "-");

 //print group permission
 printf((mode & S_IRGRP) ? "r": "-");

 printf((mode & S_IWGRP) ? "w": "-");

 printf((mode & S_IXGRP) ? "x": "-");

 //print other permissions
 printf((mode & S_IROTH) ? "r": "-");

 printf((mode & S_IWOTH) ? "w": "-");

 printf((mode & S_IXOTH) ? "x": "-");


}
