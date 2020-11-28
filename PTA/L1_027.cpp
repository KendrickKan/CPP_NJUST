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
int main()
{
    FastIO;
    string str;
    cin >> str;
    int a[10];
    mem0(a);
    rep(i, 0, str.length())
    {
        a[str[i] - '0'] = 1;
    }
    vector<int> vec;
    int num = 0;
    for (int i = 9; i >= 0; i--)
    {
        if (a[i])
        {
            num++;
            vec.push_back(i);
        }
    }
    cout << "int[] arr = new int[]{";
    for (int i = 0; i < num; i++)
    {
        if (i != (num - 1))
        {
            cout << vec[i] << ",";
        }
        else
            cout << vec[i] << "};" << endl;
    }
    cout << "int[] index = new int[]{";
    rep(i, 0, str.length())
    {
        for (int j = 0; j < num; j++)
        {
            if ((str[i] - '0') == vec[j])
                cout << j;
        }
        if (i != str.length() - 1)
            cout << ",";
        else
            cout << "};" << endl;
    }
    return 0;
}