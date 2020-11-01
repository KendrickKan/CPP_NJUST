#include <bits/stdc++.h>
using namespace std;
string str = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwx";
string strneed ="bcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxy";
int a[105];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << str << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < a[i]; j++)
                strneed[j]=str[i];
            for( int j=a[i];j<50;j++)
            {
                if(j!=49)
                    strneed[j]=str[j+1];
                else
                {
                    strneed[j]=str[a[i]];
                }     
            }
            cout<<strneed;
            cout << endl;
            str=strneed;
        }
    }

    return 0;
}
