//ctrl alt i new-head
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repp(i, a, b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for (int i = a; i >= b; i--)
#define mem0(a) memset(a, 0, sizeof(a))
#define memfu1(a) memset(a, -1, sizeof(a))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define EPS 1e-10
#define MOD 1e9 + 7
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
char ch[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
int bi[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int main()
{
    FastIO;
    int t;
    cin >> t;
    bool flag = false;
    while (t--)
    {
        string str;
        cin >> str;
        int num = 0;
        rep(i, 0, str.length() - 1)
        {
            if (str[i] < '0' || str[i] > '9')
            {
                flag = true;
                cout << str << endl;
                goto stop;
            }
            num += (str[i] - '0') * bi[i];
        }
        num %= 11;
        if (ch[num] != str[17])
        {
            flag = true;
            cout << str << endl;
        }
    stop:;
    }
    if (!flag)
        cout << "All passed";
    return 0;
}