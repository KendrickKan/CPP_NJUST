/*
 * @Author: KendrickKan 
 * @Date: 2021-02-05 23:03:49 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2021-02-06 00:25:27
 */
#include <bits/stdc++.h>
using namespace std;
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
template <typename T>
void read(T &t)
{
    t = 0;
    char ch = getchar();
    int f = 1;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    do
    {
        (t *= 10) += ch - '0';
        ch = getchar();
    } while ('0' <= ch && ch <= '9');
    t *= f;
}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int a[100005];
int b[100005];
int c[100005];
bool cd[100005];
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        mem0(a);
        mem0(b);
        mem0(c);
        mem0(cd);
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        rep(i, 0, n)
        {
            cin >> b[i];
        }
        rep(i, 0, m)
        {
            cin >> c[i];
        }
        multimap<int, int> needp;
        multimap<int, int> haveb;
        rep(i, 0, n)
        {
            haveb.insert(pii(b[i], i));
            if (b[i] != a[i])
            {
                needp.insert(pii(b[i], i));
            }
        }
        stack<int> kst;
        stack<int> stt;
        rep(i, 0, m)
        {
            if (haveb.find(c[i]) == haveb.end())
            {
                kst.push(i);
            }
        }
        bool kkflag = false;
        for (int i = m - 1; i >= 0; i--)
        {
            if (needp.find(c[i]) != needp.end())
            {
                int temp = needp.find(c[i])->second;
                needp.erase(needp.find(c[i]));
                c[i] = temp;
                cd[i] = true;
                while (kst.size() != 0)
                {
                    if (kst.top() > i)
                    {
                        kst.pop();
                        kkflag = true;
                        goto kstop;
                    }
                    else
                        break;
                }
                while (kst.size() != 0)
                {
                    c[kst.top()] = c[i];
                    cd[kst.top()] = true;
                    kst.pop();
                }
            }
            if (haveb.find(c[i]) != haveb.end() && !cd[i])
            {
                c[i] = haveb.find(c[i])->second;
                cd[i] = true;
                while (kst.size() != 0)
                {
                    c[kst.top()] = c[i];
                    cd[kst.top()] = true;
                    kst.pop();
                }
            }
        }
        rep(i, 0, m)
        {
            if (haveb.find(c[i]) == haveb.end() && !cd[i])
            {
                stt.push(i);
            }
        }
        for (int i = m - 1; i >= 0; i--)
        {
            if (haveb.find(c[i]) != haveb.end() && !cd[i])
            {
                c[i] = haveb.find(c[i])->second;
                while (stt.size() != 0)
                {
                    c[stt.top()] = c[i];
                    cd[stt.top()] = true;
                    stt.pop();
                }
            }
        }
    kstop:
        if (needp.size() != 0 || kkflag || kst.size() != 0 || stt.size() != 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (int i = 0; i < m; i++)
            {
                cout << c[i] + 1 << " ";
            }
            cout << endl;
            // stack<int> st;
            // bool kflag = false;
            // for (int i = m - 1; i >= 0; i--)
            // {
            //     if (!cd[i])
            //     {
            //         if (haveb.find(c[i]) != haveb.end())
            //         {
            //             int temp = haveb.find(c[i])->second;
            //             st.push(temp);
            //             c[i] = temp;
            //         }
            //         else
            //         {
            //             if (st.size() != 0)
            //             {
            //                 c[i] = st.top();
            //                 st.pop();
            //             }
            //             else
            //             {
            //                 kflag = true;
            //                 break;
            //             }
            //         }
            //     }
            // }
            // if (kflag)
            //     cout << "NO" << endl;
            // else
            // {
            //     cout << "YES" << endl;
            //     for (int i = 0; i < m; i++)
            //     {
            //         cout << c[i] + 1 << " ";
            //     }
            //     cout << endl;
            // }
        }
    }
    return 0;
}