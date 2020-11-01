#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int a[26];
    char ch[4][111];
    memset(ch[0], 0, sizeof(ch[0]));
    while (gets(ch[0]))
    {
        memset(ch[1], 0, sizeof(ch[0]));
        memset(ch[2], 0, sizeof(ch[0]));
        memset(ch[3], 0, sizeof(ch[0]));
        memset(a, 0, sizeof(a));
        for (int i = 1; i < 4; i++)
            gets(ch[i]);
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 111; j++)
                if (ch[i][j] >= 'A' && ch[i][j] <= 'Z')
                    a[ch[i][j] - 'A']++;
        int max = 0;
        for (int i = 0; i < 26; i++)
            if (max < a[i])
                max = a[i];
        for (int i = 0; i < max; i++)
        {
            int flag;
            for (int j = 25; j >= 0; j--)
            {
                if (i >= max - a[j])
                {
                    flag = j;
                    break;
                }
            }
            for (int j = 0; j < 26; j++)
            {
                if (i < max - a[j] && j < flag)
                    cout << "  ";
                else
                {
                    if (j < flag)

                        cout << "* ";
                    if (j == flag)
                    {
                        cout << '*' << endl;
                        break;
                    }
                }
            }
        }
        printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
        memset(ch[0], 0, sizeof(ch[0]));
    }
    return 0;
}