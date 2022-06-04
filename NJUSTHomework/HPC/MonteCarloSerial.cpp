#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
int main(int argc, char *argv[])
{
    srand(time(NULL));
    double startTime, stopTime;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    startTime = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    long long steps = strtol(argv[1], NULL, 10);
    long long hits = 0;
    for (long long i = 0; i < steps; i++)
    {
        double x = 2.0 * rand() / RAND_MAX - 1.0;
        double y = 2.0 * rand() / RAND_MAX - 1.0;
        if (x * x + y * y <= 1.0)
        {
            hits++;
        }
    }
    double pi = 4.0 * hits / steps;
    gettimeofday(&tv, NULL);
    stopTime = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    double realPi = 3.1415926535;
    double loss = abs(realPi - pi) / realPi;
    printf("\nPi = %.10lf  Loss = %.10lf  Cost = %lf ms\n\n", pi, loss, stopTime - startTime);
    return 0;
}