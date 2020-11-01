//ctrl alt i new-head
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repp(i, a, b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for (int i = a; i >= b; i--)
#define mem(a) memset(a, 0, sizeof(a))
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
    rep(i, 0, str.length() - 1)
    {
        if (str[i] == '-')
            cout << "fu"
                 << " ";
        if (str[i] == '0')
            cout << "ling"
                 << " ";
        if (str[i] == '1')
            cout << "yi"
                 << " ";
        if (str[i] == '2')
            cout << "er"
                 << " ";
        if (str[i] == '3')
            cout << "san"
                 << " ";
        if (str[i] == '4')
            cout << "si"
                 << " ";
        if (str[i] == '5')
            cout << "wu"
                 << " ";
        if (str[i] == '6')
            cout << "liu"
                 << " ";
        if (str[i] == '7')
            cout << "qi"
                 << " ";
        if (str[i] == '8')
            cout << "ba"
                 << " ";
        if (str[i] == '9')
            cout << "jiu"
                 << " ";
    }
    if (str[str.length() - 1] == '-')
        cout << "fu";
    if (str[str.length() - 1] == '0')
        cout << "ling";
    if (str[str.length() - 1] == '1')
        cout << "yi";
    if (str[str.length() - 1] == '2')
        cout << "er";
    if (str[str.length() - 1] == '3')
        cout << "san";
    if (str[str.length() - 1] == '4')
        cout << "si";
    if (str[str.length() - 1] == '5')
        cout << "wu";
    if (str[str.length() - 1] == '6')
        cout << "liu";
    if (str[str.length() - 1] == '7')
        cout << "qi";
    if (str[str.length() - 1] == '8')
        cout << "ba";
    if (str[str.length() - 1] == '9')
        cout << "jiu";
    return 0;
}