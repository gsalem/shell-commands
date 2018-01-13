/*
mytouch displays information of file
if file does not open, it then creates it
*/
#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <utime.h>

void showtime( long);
void show_stat_info( char*, struct stat* );

int main(int ac, char* argv[]){

    struct stat info;
   
      if( stat( argv[1], &info ) != -1 ) //attempt to open and display info
        {
            show_stat_info( argv[1], &info );   //open successful - print file info
            return 0;
        } 
        else
          {  creat( argv[1], 0644 ); }                   // if open failed, create that file
    
     return 0;
}

void show_stat_info( char* fname, struct stat* buf )
{
    printf( "%o", buf->st_mode );   //mode
    printf( " %d", (int)buf->st_nlink ); //links
    printf( " %d", buf->st_uid );   //user
    printf( " %d", buf->st_gid );   //group
    printf( " %d", (int)buf->st_size );     //size
    showtime(buf->st_mtime);       //display time in human readable format
    printf( " %s\n", fname );    //file name
}

void showtime( long time )
{
    char* cp;               
    cp = ctime(&time);   
    printf(" %12.12s ", cp+4 );
}