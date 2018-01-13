// Unix command raises base to the exponent and prints result
// pow BASE EXPONENT
#include "stdlib.h"
#include "stdio.h"

int main (int ac, char *args[]){
    
    float base, exp;
    
    //check if less than 3 arguments
    if( ac != 3)
    {
        printf("USAGE: %s BASE EXPONENT\n\n", args[0]);
        exit(1);
    }
    
    base = atof(args[1]);
    exp = atof(args[2]);
    
    float result = 1, i = 0;

	for (i; i < exp; ++i) {
		result *= base;
	}

    return printf("Result = %f\n", result);
}