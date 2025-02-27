// Kaustav Vats (2016048)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <grp.h>
#include <sys/xattr.h>
#include "helper.h"


int main(int argc, char const *argv[]) {

    if ( argc != 2 ) {
        printf("Usage: getacl <filename>\n");
        exit(1);
    }   
    PrintUserDetails();

    if (checkPath(argv[1]) == -1) {
        printf("Error: Path\n");
        exit(1);
    }
    
    if (checkCurrentUser(argv[1], 0) == -1) {
        perror("Owner mismatch:");   
        seteuid(getuid());
        PrintUserDetails();
        return -1;
    }
    else {
        showAclList(argv[1]);
    }

    seteuid(getuid());
    PrintUserDetails();
    
    return 0;
}

