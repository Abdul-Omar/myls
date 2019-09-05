/*
 * Filename: pa4Globals.c
 * Author: Adilijiang Ainihaer
 * Userid: cs30y11
 * Description: global variables for program
 * Date: August 22, 2017
 */

#include <stddef.h>
#include <sys/stat.h>
#include "pa4.h"

size_t offset_filename = offsetof(struct fileInfo, filename);
size_t offset_time = offsetof(struct fileInfo, time);
size_t offset_size = offsetof(struct fileInfo, size);
size_t offset_mode = offsetof(struct fileInfo, mode);
size_t offset_uid = offsetof(struct fileInfo, uid);
size_t offset_gid = offsetof(struct fileInfo, gid);
size_t offset_isDir = offsetof(struct fileInfo, isDir);
size_t offset_children = offsetof(struct fileInfo, children);
size_t offset_childrenSize = offsetof(struct fileInfo, childrenSize);
size_t offset_childrenCapacity = offsetof(struct fileInfo, childrenCapacity);

