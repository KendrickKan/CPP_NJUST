#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>
#define NUM_STEPS 1000000000
int main(int argc, char *argv[])
{
    double x, pi, step, sum = 0.0, start, stop;
    int i;
    step = 1.0 / NUM_STEPS;
    struct timeval tv;
    gettimeofday(&tv, NULL); // Record time in milliseconds
    start = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
#pragma omp parallel for reduction(+ \
                                   : sum) private(x)
    for (i = 0; i < NUM_STEPS; i++)
    {
        x = (i + 0.5) * step;
        sum = sum + 1.0 / (1.0 + x * x);
    }
    pi = 4.0 * sum * step;
    gettimeofday(&tv, NULL);
    stop = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    printf("The value of PI is %f, and the total calculation time is %f ms", pi,
           stop - start);
}