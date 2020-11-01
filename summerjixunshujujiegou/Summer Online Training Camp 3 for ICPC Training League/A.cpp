#include <bits/stdc++.h>
using namespace std;
#define Next nt
char a[1000100], b[1000100];
int nt[1000100];
inline void getnext() 
{
    int l = strlen(a), t;
    Next[0] = -1;               
    for (int i = 1; i < l; ++i) 
    {
        t = Next[i - 1];
        while (a[t + 1] != a[i] && t >= 0)
            t = Next[t];
        if (a[t + 1] == a[i])
            Next[i] = t + 1;
        else
            Next[i] = -1;
    }
}
int KMP()
{
    int l = strlen(b);
    int l2 = strlen(a);
    int i = 0, j = 0; 
    int sum = 0;
    while (i < l)
    {
        if (a[j] == b[i])
        {
            j++;
            i++;
            if (j == l2) 
            {
                ++sum;
                j = nt[j - 1] + 1;
            }
        }
        else 
        {
            if (j == 0) 
                i++;
            else 
                j = nt[j - 1] + 1;
        }
    }
    return sum;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        scanf("%s", a);
        scanf("%s", b);
        getnext();
        cout << KMP() << endl;
    }
    return 0;
}
