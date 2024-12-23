// 文件处理
#include <stdio.h>

int main()
{
    printf("第十三次课\n");
    // 文件处理，c语言提供代码和文件之间的交互
    // 文件处理的步骤
    // 1.打开文件
    // 2.读写文件
    // 3.关闭文件
    // 打开文件和关闭文件是一一对应的，打开文件之后要关闭文件
    // 打开文件
    // FILE *fopen(const char *filename, const char *mode);
    // filename 文件名 mode 打开文件的模式
    // 返回值是一个文件指针FILE *，指向文件的指针
    // FILE是一个结构体，里面包含了文件的信息，是c语言提供的一个结构体
    // mode 打开文件的模式
    // r 读文件，文件必须存在，只读模式，如果文件不存在，返回NULL
    // w 写文件，文件可以不存在，只写模式，如果文件存在，清空文件，如果文件不存在，创建文件
    // a 追加文件，文件可以不存在，追加模式，如果文件存在，文件指针指向文件的末尾，如果文件不存在，创建文件
    // r+ 读写文件，文件必须存在，读写模式，文件指针指向文件的开头
    // w+ 读写文件，文件可以不存在，读写模式，如果文件存在，清空文件，如果文件不存在，创建文件
    // a+ 读写文件，文件可以不存在，读写模式，如果文件存在，文件指针指向文件的末尾，如果文件不存在，创建文件
    // +和r/w/a组合使用，表示读写文件
    // 也可以读取二进制文件，加上b，rb wb ab r+b w+b a+b
    // 关闭文件
    // int fclose(FILE *stream);
    // 如果成功，返回0，如果失败，返回EOF，EOF是一个宏，表示文件结束符，是存在stdio.h头文件里面的
    FILE *fp = fopen("test.txt", "w+");
    if (fp == NULL)
    {
        printf("文件打开失败\n");
        return 0;
    }
    else
    {
        printf("文件打开成功\n");
        // 读写文件
        // 读文件
        // int fgetc(FILE *stream); 读取一个字符，如果读取成功，返回读取的字符，如果读取失败，返回EOF
        printf("读取文件\n");
        int ch = fgetc(fp); // 执行完这一行，文件指针指向文件的下一个字符
        if (ch == EOF)
        {
            printf("读取文件失败\n");
        }
        else
        {
            printf("读取文件成功\n");
            printf("ch = %c\n", ch);
        }
        // fgets 读取一行
        // char *fgets(char *s, int size, FILE *stream); 读取一行，如果读取成功，返回读取的内容，如果读取失败，返回NULL
        // s 读取的内容存放的位置
        // size 读取的内容的大小
        // stream 文件指针
        char buf[1024]; // 读取的内容存放的位置
        char *p = fgets(buf, 1024, fp);
        if (p == NULL)
        {
            printf("读取文件失败\n");
        }
        else
        {
            printf("读取文件成功\n");
            printf("buf = %s\n", buf);
        }
        // 执行完fgets之后，文件指针指向文件的下一行
        // fscanf(FILE *stream, const char *format, ...); 读取一个字符串，如果读取成功，返回读取的内容，如果读取失败，返回NULL
        // fscanf(fp, "%s", buff); // 读取一个字符串 "%s"是格式化字符串，buff是存放读取内容的位置
        // fp 是文件指针，%s是格式化字符串，buff是存放读取内容的位置
        // 写文件
        // int fputc(int c, FILE *stream); 写一个字符，如果写入成功，返回写入的字符，如果写入失败，返回EOF
        char ch1 = 'A';
        int ret = fputc(ch1, fp);
        if (ret == EOF)
        {
            printf("写入文件失败\n");
        }
        else
        {
            printf("写入文件成功\n");
        }
        // int fputs(const char *s, FILE *stream); 写一行，如果写入成功，返回的是一个非负数，如果写入失败，返回EOF
        char *str = "hello world";
        int ret1 = fputs(str, fp);
        if (ret1 == EOF)
        {
            printf("写入文件失败\n");
        }
        else
        {
            printf("写入文件成功\n");
        }
        fclose(fp); // 关闭文件
    }
    return 0;
}