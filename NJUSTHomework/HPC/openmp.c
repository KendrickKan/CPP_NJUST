#include "omp.h"
#include <stdio.h>
#include <unistd.h>

void test1()
{

#pragma omp parallel // num_threads(4)
    {
        printf("parallel@%d\n", omp_get_thread_num());
    }

    printf("serial@%d\n", omp_get_thread_num());
}

void test2()
{
#pragma omp parallel for
    for (int i = 0; i < 8; i++)
    {
        printf("parallel for %d@%d\n", i, omp_get_thread_num());
    }
    printf("serial@%d\n", omp_get_thread_num());
}

void test3()
{
#pragma omp for
    for (int i = 0; i < 8; i++)
    {
        printf("for %d@%d\n", i, omp_get_thread_num());
    }

#pragma omp parallel
    {
#pragma omp for nowait
        for (int i = 0; i < 8; i++)
        {
            printf("parallel for_1 %d@%d\n", i, omp_get_thread_num());
        }

#pragma omp for
        for (int i = 8; i < 16; i++)
        {
            printf("parallel for_2 %d@%d\n", i, omp_get_thread_num());
        }
    }
    printf("serial@%d\n", omp_get_thread_num());
}

void test4()
{
#pragma omp parallel
    {
#pragma omp single // nowait
        {
            printf("single@%d\n", omp_get_thread_num());
            sleep(1);
        }

        printf("parallel@%d\n", omp_get_thread_num());
    }
    printf("serial@%d\n", omp_get_thread_num());
}

void test5()
{
#pragma omp parallel for schedule(guided, 1) // static,dynamic,guided,runtime
    for (int i = 0; i < 8; i++)
    {
        printf("parallel for %d@%d\n", i, omp_get_thread_num());
    }
    printf("serial@%d\n", omp_get_thread_num());
}

void test6()
{
#pragma omp sections
    {
#pragma omp section
        printf("section_1@%d\n", omp_get_thread_num());
#pragma omp section
        printf("section_2@%d\n", omp_get_thread_num());
#pragma omp section
        printf("section_3@%d\n", omp_get_thread_num());
#pragma omp section
        printf("section_4@%d\n", omp_get_thread_num());
    }

#pragma omp parallel sections
    {
#pragma omp section
        printf("section_1@%d\n", omp_get_thread_num());
#pragma omp section
        printf("section_2@%d\n", omp_get_thread_num());
#pragma omp section
        printf("section_3@%d\n", omp_get_thread_num());
#pragma omp section
        printf("section_4@%d\n", omp_get_thread_num());
    }
}

void test7()
{
    int sum = 0;
#pragma omp parallel for
    for (int i = 0; i < 10; i++)
    {
#pragma omp critical(sum)
        {
            sum += i;
            printf("parallel for %d:%d@%d\n", i, sum, omp_get_thread_num());
        }
    }
    printf("serial :%d@%d\n", sum, omp_get_thread_num());
}

void test8()
{
    int sum = 0;
    omp_lock_t lock;
    omp_init_lock(&lock);
#pragma omp parallel for
    for (int i = 0; i < 10; i++)
    {
        omp_set_lock(&lock);
        sum += i;
        printf("parallel for %d:%d@%d\n", i, sum, omp_get_thread_num());
        omp_unset_lock(&lock);
    }
    printf("serial :%d@%d\n", sum, omp_get_thread_num());
    omp_destroy_lock(&lock);
}

void test9()
{
    int cnt = 0;
#pragma omp parallel for
    for (int i = 0; i < 10; i++)
    {
#pragma omp automic
        cnt++;
    }
    printf("%d\n", cnt);
}

void test10()
{
#pragma omp parallel
    {
        if (omp_get_thread_num() == 0)
        {
            sleep(1);
        }
#pragma omp barrier
        printf("ok@%d\n", omp_get_thread_num());
    }
}

void test11()
{
#pragma omp parallel
    {
#pragma omp for nowait
        for (int i = 0; i < 4; i++)
        {
            printf("parallel for_1 %d@%d\n", i, omp_get_thread_num());
        }
#pragma omp master
        for (int i = 4; i < 8; i++)
        {
            printf("parallel for_2 %d@%d\n", i, omp_get_thread_num());
        }
#pragma omp for ordered
        for (int i = 8; i < 12; i++)
        {
#pragma omp ordered
            printf("parallel for_3 %d@%d\n", i, omp_get_thread_num());
        }
    }
    printf("serial@%d\n", omp_get_thread_num());
}

void test12()
{
    int i = 0;
    int j = 0;
#pragma omp parallel for private(j)
    for (i = 0; i < 5; i++)
    {

        for (j = 0; j < 2; j++)
        {
            printf("i:%d,j:%d@%d\n", i, j, omp_get_thread_num());
        }
    }
    printf("serial --- i:%d,j:%d@%d\n", i, j, omp_get_thread_num());
}

void test13()
{
    int sum = 10;
#pragma omp parallel firstprivate(sum)
    {
        printf("parallel %d@%d\n", sum, omp_get_thread_num());
    }
    printf("serial %d@%d\n", sum, omp_get_thread_num());
#pragma omp parallel sections lastprivate(sum)
    {
#pragma omp section
        {
            sum = 1;
            printf("section_1 %d@%d\n", sum, omp_get_thread_num());
        }

#pragma omp section
        {
            sum = 2;
            printf("section_2 %d@%d\n", sum, omp_get_thread_num());
        }

#pragma omp section
        {
            sum = 3;
            printf("section_3 %d@%d\n", sum, omp_get_thread_num());
        }

#pragma omp section
        {
            sum = 4;
            printf("section_4 %d@%d\n", sum, omp_get_thread_num());
        }
    }
    printf("serial %d@%d\n", sum, omp_get_thread_num());
}

void test14()
{
    int cnt = 0;
#pragma omp parallel for reduction(+ \
                                   : cnt)
    for (int i = 0; i < 10; i++)
    {
        cnt++;
        printf("parallel for %d:%d@%d\n", i, cnt, omp_get_thread_num());
    }
    printf("serial %d@%d\n", cnt, omp_get_thread_num());
}

int G = 100;
#pragma omp threadprivate(G)
void test15()
{
#pragma omp parallel for // copyin(G)
    for (int i = 0; i < 8; i++)
    {
        G++;
        printf("parallel for+ %d:%d@%d\n", i, G, omp_get_thread_num());
    }
#pragma omp parallel
    {
#pragma omp single copyprivate(G)
        {
            G = 0;
            printf("single %d@%d\n", G, omp_get_thread_num());
        }
#pragma omp for
        for (int i = 0; i < 8; i++)
        {
            G--;
            printf("parallel for- %d:%d@%d\n", i, G, omp_get_thread_num());
        }
    }

    printf("serial %d@%d\n", G, omp_get_thread_num());
}

void test16()
{
    int a[5] = {1, 2, 3, 4, 5};
#pragma omp parallel
    {
#pragma omp single
        {
            printf("single@%d\n", omp_get_thread_num());
            sleep(1);

            for (int i = 0; i < 5; i += a[i])
            {
#pragma omp task
                {
                    sleep(1);
                    printf("single %d@%d\n", i, omp_get_thread_num());
                }
            }
        }
    }
}
int main()
{

    omp_set_num_threads(4);
    test1();
    return 0;
}