#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    printf("Number of arguments passed: %d\n", argc);
    for(int i=0; i<argc; i++){
        printf("Argument %d. %s\n", i+1, argv[i]);
    }
    int sum = 0;
    for (int i = 1; i < argc; i++)
    {
        sum += atoi(argv[i]);   //atoi() function is used to convert 'STRING TO INTEGER TYPE' and for its use one must use #include <stdlib.h>
    }
    printf("Sum of the integers passed as Command Line Arguments: %d\n", sum);
    return 0;
}