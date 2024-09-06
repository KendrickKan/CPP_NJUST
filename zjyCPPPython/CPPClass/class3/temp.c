#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int a = atoi(argv[1]);
    float b = atof(argv[2]);
    printf("a = %d, b = %f\n", a, b);
    return 0;
}