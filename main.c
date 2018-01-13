#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
    
#define oops(s, x) { perror(s); exit(x); }

int main(int ac, char* av[])
{
    int n = atoi (av[0]);   //input
    
    struct termios og, settings;

    
    if( tcgetattr( 0, &settings ) == -1 )
        oops( "tcgetattr", 1 );
            
    settings.c_cc[VMIN] = 1;                //get 1 char
    settings.c_lflag   &= ~(ICANON | ECHO); //turn icanon and echo off
   
   while (ac != 0){
       switch(n)
        {
            case 'w':
            case 'W':
                printf("UP\n");
            case 'a': 
            case 'A':    
                printf("LEFT\n");
            case 's':    
            case 'S': 
                printf("RIGHT\n");
            case 'd':
            case 'D':    
                printf("DOWN\n");
            default: 
                break;
        }
   }
    if( tcsetattr( 0, TCSANOW, &settings ) == -1 )  //set attribs
        oops( "tcsetattr", 2 );   
    
    tcsetattr( 0, TCSANOW, &og ); //set original attributes back
    return 0;
}