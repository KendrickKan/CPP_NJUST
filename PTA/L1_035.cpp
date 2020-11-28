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
string str[10005];
int main()
{
    FastIO;
    int num = 0;
    string temp;
    cin >> temp;
    str[num] = temp;
    while (temp != ".")
    {
        num++;
        cin >> temp;
        str[num] = temp;
    }
    if (num <= 1)
        cout << "Momo... No one is for you ..." << endl;
    else if (num >= 2 && num < 14)
        cout << str[1] << " is the only one for you..." << endl;
    else
    {
        cout << str[1] << " and " << str[13] << " are inviting you to dinner..." << endl;
    }

    return 0;
}