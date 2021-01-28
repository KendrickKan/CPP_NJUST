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
const int MOD = 1e9 + 7;
//INT_MAX <limits>
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second < b.second;
}
int main()
{
    FastIO;
    int n;
    cin >> n;
    map<string, int> km;
    int x = 0;
    rep(i, 0, n)
    {
        string str;
        cin >> str;
        if (str == "touch")
        {
            string name;
            cin >> name;
            if (km.find(name) == km.end())
            {
                pair<string, int> temp;
                temp.first = name;
                temp.second = x;
                x++;
                km.insert(temp);
            }
        }
        else if (str == "rm")
        {
            string name;
            cin >> name;
            if (km.find(name) != km.end())
            {
                km.erase(name);
            }
        }
        else if (str == "rename")
        {
            string name1, name2;
            cin >> name1;
            cin >> name2;
            if (km.find(name1) != km.end() && km.find(name2) == km.end())
            {
                pair<string, int> temp;
                temp.second = km.find(name1)->second;
                temp.first = name2;
                km.erase(name1);
                km.insert(temp);
            }
        }
        else if (str == "ls")
        {
            vector<pair<string, int>> vec;
            map<string, int>::iterator it = km.begin();
            for (it; it != km.end(); it++)
            {
                vec.push_back(*it);
            }
            sort(vec.begin(), vec.end(), cmp);
            for (int j = 0; j < vec.size(); j++)
            {
                cout << vec[j].first << endl;
            }
        }
    }
    return 0;
}