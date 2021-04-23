/*
 * @Author: KendrickKan 
 * @Date: 2020-11-01 19:45:51 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2020-11-06 19:46:34
 */
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
class Polynomial
{ //定义多项式类
    int n;
    double (*p)[2];

public:
    Polynomial(double poly[][2], int num)
    { //构造函数，带两个参数
        n = num;
        p = new double[n][2];
        for (int i = 0; i < n; i++)
        {
            p[i][0] = poly[i][0];
            p[i][1] = poly[i][1];
        }
    }
    Polynomial(int num)
    { //构造函数，带一个参数
        n = num;
        p = new double[num][2];
        for (int i = 0; i < n; i++)
        {
            p[i][0] = 0;
            p[i][1] = 0;
        }
    }

    friend Polynomial operator+(Polynomial &c1, Polynomial &c2)
    {
        int i, j, tn;
        Polynomial t(c2.n + c1.n);
        tn = c1.n;
        for (i = 0; i < c1.n; i++)
        {
            t.p[i][0] = c1.p[i][0];
            t.p[i][1] = c1.p[i][1];
        }
        for (i = 0; i < c2.n; i++)
        {
            for (j = 0; j < t.n; j++)
            {
                if (c2.p[i][1] == t.p[j][1])
                {
                    t.p[j][0] += c2.p[i][0];
                    break;
                }
                else if (j >= tn)
                {
                    t.p[j][0] = c2.p[i][0];
                    t.p[j][1] = c2.p[i][1];
                    tn++;
                    break;
                }
                else if (c2.p[i][1] < t.p[j][1])
                {
                    for (int k = t.n - 1; k > j; k--)
                    {
                        t.p[k][0] = t.p[k - 1][0];
                        t.p[k][1] = t.p[k - 1][1];
                    }
                    t.p[j][0] = c2.p[i][0];
                    t.p[j][1] = c2.p[i][1];
                    tn++;
                    break;
                }
                else if (c2.p[i][1] > t.p[j][1])
                    continue;
            }
        }
        t.n = tn;
        return t;
    }

    friend Polynomial operator-(Polynomial &c1, Polynomial &c2)
    {
        Polynml t(c2.n);
        for (int i = 0; i < t.n; i++)
        {
            t.p[i][0] = -c2.p[i][0];
            t.p[i][1] = c2.p[i][1];
        }
        return c1 + t;
    }

    friend Polynomial operator*(Polynomial &c1, Polynomial &c2)
    {
        Polynomial t(c1.n * c2.n);
        int i, j, m = 0;
        for (i = 0; i < c1.n; i++)
        {
            for (j = 0; j < c2.n; j++)
            {
                t.p[m][0] = c1.p[i][0] * c2.p[j][0];
                t.p[m][1] = c1.p[i][1] + c2.p[j][1];
                m++;
            }
        }
        return t;
    }

    friend bool operator==(Polynomial &c1, Polynomial &c2)
    {
        if (c1.n != c2.n)
            return false;
        else
        {
            rep(i, 0, c1.n)
            {
                if ((c1.p[i][1] != c2.p[i][1]) && (c1.p[i][2] == c2.p[i][2]))
                    return false;
            }
            return true;
        }
    }
    friend bool operator!=(Polynomial &c1, Polynomial &c2)
    {
        if (c1.n != c2.n)
            return true;
        else
        {
            rep(i, 0, c1.n)
            {
                if ((c1.p[i][1] != c2.p[i][1]) && (c1.p[i][2] == c2.p[i][2]))
                    return true;
            }
            return false;
        }
    }
    ~Polynomial()
    {
        delete[] p;
    }
};

int main()
{
    FastIO;

    return 0;
}