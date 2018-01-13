/*
compiles but exits right away
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> //chdir, execvp
#include <wait.h> 
#include<signal.h>
#include<string.h>
#include <sys/types.h>

#ifndef PARSE_H
#define PARSE_H

#define BUFFER_LEN 1024

int main( int ac, char* args[]){
    int i = 0;
    
    printf("$ >> ");
   
    //parse cmdline
    char input[BUFFER_LEN];
    input[strlen(input)-1] = '\0';    // fgets reads the \n, so overwrite it
    args[i] = strtok( input, " " );   // get the first token
    while( ( args[++i] = strtok(NULL, " ") ) );    // get the rest of them
    
    
    //fork
    pid_t pid, wpid;
    pid = fork();
    
    if ( pid == -1 )     // check for error
       { perror( "fork" );}

    if ( pid != 0 )    //parent
        waitpid(pid, &i, WUNTRACED | WCONTINUED);
    else                        //child
       execvp(*args, args);

        
    return 1;
}
#endif