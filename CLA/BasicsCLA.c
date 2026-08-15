#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    /*IMPORTANT POINTS TO NOTE -->
    1. argc --> Argument count - counts the number of arguments passed to the function during the execution of the executable file (a.exe)
    2. argv --> Argument vector - stores all the command line arguments passed during execution, including a.exe as 'AN ARRAY OF STRINGS'
    */
    printf("Number of arguments passed: %d\n", argc);
    for(int i=0; i<argc; i++){
        printf("Argument %d. %s\n", i+1, argv[i]);
    }
    //OUTPUT -->
    /*
    Number of arguments passed: 3
    Argument 1. C:\Users\daksh\OneDrive\Desktop\DSA\DSA COURSE\CLA\a.exe
    Argument 2. 10
    Argument 3. 20
    */
    return 0;
}