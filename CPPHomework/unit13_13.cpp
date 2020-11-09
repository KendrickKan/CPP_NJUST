/*
 * @Author: KendrickKan 
 * @Date: 2020-11-01 19:46:40 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2020-11-06 20:02:28
 */
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
class TMatrix
{
public:
    int n, m;
    int a[500][500];
    TMatrix(int n, int m, int *p);
    TMatrix operator+(const TMatrix &temp)
    {
        rep(i, 0, n)
        {
            rep(j, 0, m)
            {
                a[i][j] += temp.a[i][j];
            }
        }
    }
    TMatrix operator-(const TMatrix &temp)
    {
        rep(i, 0, n)
        {
            rep(j, 0, m)
            {
                a[i][j] += temp.a[i][j];
            }
        }
    }
    TMatrix operator*(const TMatrix &temp)
    {
        int x, y;
        x = this->n;
        y = temp.m;
        int *p = new int[x * y];
        rep(i, 0, n * m)
        {
            int tempnum = 0;
            int tempx = i / y;
            int tempy = i % y;
            rep(j, 0, m)
            {
                tempnum += this->a[tempx][tempy] * (temp.a[tempx][tempy]);
            }
            p[i] = tempnum;
        }
        TMatrix ans(x, y, p);
        return ans;

        delete p;
    }
};
TMatrix::TMatrix(int n, int m, int *p)
{
    mem0(a);
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            a[i][j] = *p;
            p++;
        }
    }
}
int main()
{
    FastIO;

    return 0;
}