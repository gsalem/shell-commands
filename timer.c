#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

void p(int);    //pause

int main(int ac, char* args[])
{
    struct termios settings, backup;

    int result;
    int i = atoi(args[0]); //second arugument for num countdown
    
    result = tcgetattr(0, &settings);
    result = tcgetattr(0, &backup);
    
    if(result == -1)
    {
        perror("Failed to get settings");
        exit(1); 
    }
    
    settings.c_lflag &= ~ICANON;    // turn off canonical mode
    settings.c_lflag &= ~ECHO;      // turn off echoing
    result = tcsetattr(0, TCSANOW, &settings); // update the settings

    signal( SIGINT, p );         //install signal handler for pause
    signal( SIGINT, SIG_IGN );    //SIG_QUIT terminate
    
    for( i ; i > 0; i-- ) //countdown
    {
        printf("%d\n", i);  //display number
        sleep(1);           //1 sec delay
        
    }
    
    
    result = tcsetattr(0, TCSANOW, &backup);    //restore settings

    return 0;

}
//pause function
void p( int signum )
{
    while(pause){};
}
