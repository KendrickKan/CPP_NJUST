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
struct Peoson
{
    char sex;
    string father;
};
map<string, Peoson> people;
bool judge(string a, string b)
{
    int i = 1, j;
    for (string A = a; !A.empty(); A = people[A].father, i++)
    {
        j = 1;
        for (string B = b; !B.empty(); B = people[B].father, j++)
        {
            if (A == B && (i < 5 || j < 5))
                return 0;
        }
    }
    return 1;
}
int main()
{
    FastIO;
    int n, m;
    string str, a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (b.back() == 'n')
            people[a] = {'m', b.substr(0, b.size() - 4)};
        else if (b.back() == 'r')
            people[a] = {'f', b.substr(0, b.size() - 7)};
        else
            people[a].sex = b.back();
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> str >> b >> str;
        if (people.find(a) == people.end() || people.find(b) == people.end())
            cout << "NA" << endl;
        else if (people[a].sex == people[b].sex)
            cout << "Whatever" << endl;
        else
        {
            if (judge(a, b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}