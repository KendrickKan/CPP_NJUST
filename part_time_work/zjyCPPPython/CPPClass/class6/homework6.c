#include <stdio.h>

int main(int argc, char *argv[])
{
    char arr[100] = {0};
    for (int i = 0; i < argc - 1; i++)
    {
        arr[i] = *argv[i + 1];
    }
    printf("%s\n", arr);
    return 0;
}