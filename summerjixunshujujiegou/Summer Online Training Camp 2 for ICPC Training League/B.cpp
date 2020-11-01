#include <stdio.h>
#include <string.h>
#include <algorithm>
#define met(a) memset(a, 0, sizeof(a));
using namespace std;
typedef long long ll;
const int maxn = 500050;
char s[maxn];
char s_new[maxn * 2];
int p[maxn * 2];
int sum[maxn];
int Init()
{
    int len = strlen(s);
    s_new[0] = '$';
    s_new[1] = '#';
    int j = 2;
    for (int i = 0; i < len; i++)
    {
        s_new[j++] = s[i];
        s_new[j++] = '#';
    }
    s_new[j] = '\0';
    return j;
}
void Manacher()
{
    int len = Init();
    int id;
    int mx = 0;
    for (int i = 1; i < len; i++)
    {
        if (i < mx)
            p[i] = min(p[2 * id - i], mx - i);
        else
            p[i] = 1;
        while (s_new[i - p[i] == s_new[i + p[i]]])
        {
            p[i]++;
        }
        if (mx < i + p[i])
        {
            id = i;
            mx = i + p[i];
        }
    }
    return;
}
int main()
{
    int t;
    scanf("%d", &t);
    int v[26];
    while (t--)
    {
        met(p);
        for (int i = 0; i < 26; i++)
            scanf("%d", &v[i]);
        scanf("%s", s);
        sum[0] = v[s[0] - 'a'];
        for (int i = 1; s[i]; i++)
        {
            sum[i] = sum[i - 1] + v[s[i] - 'a'];
        }
        Manacher();
        int Mx = 0;
        int len = strlen(s);
        for (int i = 0; i < len; i++)
        {
            int tmp = 0;
            int num = p[i + 2] - 1;
            if (num == i + 1)
                tmp += sum[i];
            num = p[i + len + 2] - 1;
            if (num == len - i - 1)
                tmp += sum[len - 1] - sum[i];
            if (tmp > Mx)
                Mx = tmp;
        }
        printf("%D\n",Mx);
    }

    return 0;
}
// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <algorithm>

// using namespace std;

// const int maxn = 550000;
// const int INF = 0x3f3f3f3f;

// char str[maxn], ans[maxn * 2];
// int p[maxn * 2], table[30], sum[maxn * 2];
// int pal[maxn * 2], par[maxn * 2];

// void pre()
// {
//     int tot = 1;
//     memset(ans, 0, sizeof(ans));
//     ans[0] = '$';
//     int len = strlen(str);
//     for (int i = 0; i < len; i++)
//     {
//         ans[tot] = '#';
//         tot++;
//         ans[tot] = str[i];
//         tot++;
//     }
//     ans[tot] = '#';
// }

// void manacher()
// {
//     pre();
//     memset(p, 0, sizeof(p));
//     int len = strlen(ans);
//     int mid = -1, mx = -1;
//     for (int i = 0; i < len; i++)
//     {
//         int j = -1;
//         if (i < mx)
//         {
//             j = 2 * mid - i;
//             p[i] = min(p[j], mx - i);
//         }
//         else
//             p[i] = 1;

//         while (i + p[i] < len && ans[i + p[i]] == ans[i - p[i]])
//             p[i]++;

//         if (p[i] + i > mx)
//         {
//             mx = p[i] + i;
//             mid = i;
//         }
//     }
// }

// int main()
// {
//     int T_T;
//     scanf("%d", &T_T);
//     while (T_T--)
//     {
//         for (int i = 0; i < 26; i++)
//             scanf("%d", table + i);
//         scanf("%s", str);
//         manacher();
//         sum[0] = 0;
//         int sz = strlen(ans);
//         for (int i = 1; i < sz; i++)
//         {
//             sum[i] = sum[i - 1];
//             if (ans[i] >= 'a' && ans[i] <= 'z')
//             {
//                 sum[i] += table[ans[i] - 'a'];
//             }
//         }
//         ans[1] = '$';
//         ans[sz - 1] = '$';
//         int ret = -INF;
//         memset(pal, 0, sizeof(pal));
//         memset(par, 0, sizeof(par));
//         for (int i = 2; i < sz; i++)
//         {
//             int r = p[i] - 1;
//             int L = i - r, R = i + r;
//             if (ans[L] == '$' && ans[R] == '$')
//                 continue; ///必须要割两段
//             if (ans[L] == '$')
//             {
//                 ///后一半可能是回文串，要把结果记录到右端点去
//                 par[R] = sum[R];
//                 if (!(ans[R] >= 'a' && ans[R] <= 'z'))
//                     par[R - 1] = sum[R];
//                 else
//                     par[R + 1] = sum[R];
//             }
//             else if (ans[R] == '$')
//             {
//                 ///前一半可能是回文串，要把结果记录到左端点去
//                 int temp = sum[R] - sum[L - 1];
//                 pal[L] = temp;
//                 if (!(ans[L] >= 'a' && ans[L] <= 'z'))
//                     pal[L + 1] = temp;
//                 else
//                     pal[L - 1] = temp;
//             }
//         }
//         ///统计答案
//         for (int i = 2; i < sz; i++)
//         {
//             int r = p[i] - 1;
//             int L = i - r, R = i + r;
//             if (ans[L] == '$' && ans[R] == '$')
//                 continue; ///必须要割两段

//             if (ans[L] == '$')
//             {
//                 ret = max(ret, sum[R] + pal[R + 1]);
//             }
//             else if (ans[R] == '$')
//             {
//                 int temp = sum[R] - sum[L - 1];
//                 ret = max(ret, temp + par[L - 1]);
//             }
//             else
//                 ret = max(0, ret); ///当存在负数值的时候0可能是最大的
//         }
//         printf("%d\n", ret);
//     }
//     return 0;
// }