#include <stdio.h>

int main(int ac, char* args[])
{
  int dir;
        if (args[1] == NULL) //print out USAGE
        {
            printf("Usage: dirp OPTION FILE [FILE]\n");
        } 
        else
        if(strcmp(args[1], "-c") == 0) //create directory
        { 
            dir = mkdir(args[2], 0744);
        } 
    else    
        if(strcmp(args[1], "-d") == 0) //remove directory
        { 
            if(dir=rmdir(args[2]) == -1){
                perror(args[2]);
            };
        }
    else 
        if(strcmp(args[1], "-r") == 0)  //renames directory
        { 
            dir=rename(args[2],args[3]);
        }
    
    close(dir);
  return 0;
}