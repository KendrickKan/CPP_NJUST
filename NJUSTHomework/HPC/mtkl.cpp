#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define DART 1000000000
#define MAXPLAYER 4
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
int player(int playersDarts)
{
    srand(time(NULL));
    double pi, x, y;
    int score = 0;
    for (int i = 0; i < playersDarts; i++)
    {
        x = fRand(-1.0, 1.0);
        y = fRand(-1.0, 1.0);
        if (x * x + y * y < 1.0)
            score++;
    }
    return score;
}
int main()
{
    double pi;
    double REAL_PI = 3.141592653589;
    int score = 0, playersDarts;
    // Parallel Execution
    playersDarts = DART / MAXPLAYER;
    double beginParallel = omp_get_wtime();
#pragma omp parallel for
    for (int i = 1; i <= MAXPLAYER; i++)
        score += player(playersDarts);
    double endParallel = omp_get_wtime();
    pi = 4.0 * ((double)score / (double)DART);
    double time_spent_parallel = endParallel - beginParallel;
    printf("\n\t Calculated pi : %.12Lf\n", pi);
    printf("\t Real pi : %.12Lf\n", REAL_PI);
    printf("\n\t Parallel Execution Time: %f\n", time_spent_parallel);
    // Serial Execution
    double beginSerial = omp_get_wtime();
    pi = 4.0 * ((double)player(DART) / (double)DART);
    double endSerial = omp_get_wtime();
    double time_spent_serial = endSerial - beginSerial;
    printf("\n\t Calculated pi : %.12Lf\n", pi);
    printf("\t Real pi : %.12Lf\n", REAL_PI);
    printf("\n\t Serial Execution Time: %f\n", time_spent_serial);
    return 1;
}