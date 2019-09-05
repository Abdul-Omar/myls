/*
 * Filename: pa4Strings.h
 * Author: Adilijiang Ainihaer
 * Userid: cs30y11
 * Description: strings used in pa4
 */

#ifndef PA4_STRINGS_H
#define PA4_STRINGS_H

#define STR_USAGE \
"Usage: %s [-aclrth] [-f file]\n"\
"  -a \t show all files, including hidden files\n"\
"  -c \t print file count, including hidden files\n"\
"  -f \t [file] specify directory to list\n"\
"  -l \t list files in long format\n"\
"  -r \t sort files in reversed order\n"\
"  -t \t sort files by time, instead of by name\n"\
"  -h \t show the help message\n"

#define STR_EXTRA_ARG "Extra argument %s detected\n"

#define STR_SIZE "%5d "
#define STR_GNAME "%-8s "
#define STR_PWNAME "%-8s "
#define STR_COUNT "File count in \"%s\": %d.\n"
#define ERR_DNE "File/directory \"%s\" does not exist.\n"

/*permission for printPermissions()*/
#define D_PERMISSION "d"
#define R_PERMISSION "r"
#define W_PERMISSION "w"
#define X_PERMISSION "x"
#define NO_PERMISSION "-"

/*options and flag strings for getopt*/
#define FLAGS "aclrtf:h"
#define FLAG_SHOWHIDDEN 'a'
#define FLAG_COUNT 'c'
#define FLAG_LONGFMT 'l'
#define FLAG_REVERSE 'r'
#define FLAG_TIME 't'
#define FLAG_FILENAME 'f'
#define FLAG_HELP 'h'
#define FLAG_UNKNOWN '?'

#define STR_THIS "."
#define STR_UP ".."
#define CHAR_THIS '.'
#define CHAR_FILESEPARATOR '/'

#define FILE_CONCAT_FORMAT "%s/%s"

#endif /* PA4_STRINGS_H */
