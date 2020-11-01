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
struct kdistract
{
    int bangpai;
    int loc;
    bool havelink;
    bool ismin;
};
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> vec(1e9 + 7);
        kdistract a[5005];
        rep(i, 0, n)
        {
            cin >> a[i].bangpai;
            vec[a[i].bangpai].first = a[i].bangpai;
            vec[a[i].bangpai].second++;
            a[i].loc = i + 1;
            a[i].havelink = false;
            a[i].ismin = false;
        }
        sort(vec.begin(), vec.end(), cmp);
        int minbangpai;
        int minnum;
        if (vec[1].second == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (int i = 1; i < n; i++)
            {
                if (vec[i].second == 0)
                {
                    minbangpai = vec[i - 1].first;
                    minnum = vec[i - 1].second;
                    break;
                }
            }
            int minbangpaibianhao[5005];
            int temp = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i].bangpai == minbangpai)
                {
                    a[i].ismin = true;
                    minbangpaibianhao[temp] = i + 1;
                    temp++;
                }
            }
            int j = 0;
            for (int i = 0; i < minnum - 1; i++)
            {
                for (j; j < n; j++)
                {
                    if (a[j].ismin == false)
                    {
                        cout << j + 1 << " " << minbangpaibianhao[i] << endl;
                        cout << j + 1 << " " << minbangpaibianhao[i + 1] << endl;
                    }
                }
            }
            for (j; j < n; j++)
            {
                cout << j + 1 << " " << minbangpaibianhao[0] << endl;
            }
        }
    }
    return 0;
}