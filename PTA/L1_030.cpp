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
struct people
{
    int sex;
    string name;
    bool ifchoose;
};
int main()
{
    FastIO;
    int n;
    cin >> n;
    people p[55];
    for (int i = 0; i < n; i++)
    {
        int a;
        string str;
        cin >> a;
        cin >> str;
        people temp;
        temp.sex = a;
        temp.name = str;
        temp.ifchoose = false;
        p[i] = temp;
    }
    for (int i = 0; i < n / 2; i++)
    {
        cout << p[i].name << " ";
        int x;
        if (p[i].sex == 1)
            x = 0;
        else
            x = 1;
        for (int j = n - 1; j > 0; j--)
        {
            if (p[j].sex == x && p[j].ifchoose == false)
            {
                cout << p[j].name << endl;
                p[j].ifchoose = true;
                break;
            }
        }
    }
    return 0;
}