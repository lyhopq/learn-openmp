#include "stdio.h"

int main(int agrc, char* aggv[])
{
#pragma omp parallel
    printf("Hello, world.\n");
    return 0;
}

// g++ hello_world.c -fopenmp 
