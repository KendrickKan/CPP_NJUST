#include <bits/stdc++.h>
#include <sys/time.h>
#include <omp.h>
using namespace std;
int main(int argc, char *argv[])
{
    srand(time(NULL));
    double startTime, stopTime;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    startTime = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    int steps = strtol(argv[1], NULL, 10);
    int hits = 0;
#pragma omp parallel for reduction(+ \
                                   : hits)
    for (int i = 0; i < steps; i++)
    {
        double x = rand() / double(RAND_MAX);
        double y = rand() / double(RAND_MAX);
        if (x * x + y * y <= 1.0)
        {
            hits++;
        }
    }
    double pi = 4.0 * hits / steps;
    gettimeofday(&tv, NULL);
    stopTime = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    cout << pi << " " << stopTime - startTime << endl;
}