#include "stdlib.h"
#include "stdio.h"
#include "errno.h"
#include "unistd.h"
#include "fcntl.h" 

#define BUFFERSIZE  4096
#define COPYMODE    0644


void oops( char* s1, char* s2 )
{
    perror( s2 );
    exit( 1 );
}

int main (int ac, char *args[]){
    
    char buf[BUFFERSIZE];
    
    int fd = open( args[1], O_RDONLY );
    
    // Error check
    if (fd == -1){
        oops( "Cannot open", args[1] );
        exit(1);
    } 
    else
     read( fd, buf, 128 ); // read from file
     printf("%s\n", buf );

    // close file
    if ( close( fd ) == -1 )
        oops( "Error closing files", "" );
}
