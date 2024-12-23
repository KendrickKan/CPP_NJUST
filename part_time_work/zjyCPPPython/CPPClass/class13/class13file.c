#include <stdio.h>

int main()
{
    FILE *fp = NULL;
    char buff[255];

    fp = fopen("test.txt", "r");
    // fscanf(fp, "%s", buff); // 读取一个字符串
    // fp 是文件指针，%s是格式化字符串，buff是存放读取内容的位置
    fscanf(fp, "%s", buff);
    printf("1: %s\n", buff);

    fgets(buff, 255, (FILE *)fp);
    printf("2: %s\n", buff);

    // fscanf和fgets的区别，fscanf读取一个字符串，遇到空格就结束，fgets读取一行，遇到换行符就结束
    fclose(fp);
}