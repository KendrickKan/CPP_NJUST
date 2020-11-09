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
bool compfile(const char *file1, const char *file2)
{
    int i;
    string line1[1005], line2[1005];
    ifstream infile1, infile2;
    infile1.open(file1);
    infile2.open(file2);
    int x1, x2;
    x1 = x2 = 0;
    while (getline(infile1, line1[x1]))
    {
        x1++;
    }
    while (getline(infile2, line2[x2]))
    {
        x2++;
    }
    infile1.close();
    infile2.close();
    int x = x1 > x2 ? 1 : 2;
    for (int i = 0; i < min(x1, x2); i++)
    {
        string tempx, tempy;
        tempx = "";
        tempy = "";
        int temp1begin, temp1end;
        for (int j = 0; j < line1[i].length(); j++)
        {
            if (line1[i][j] != ' ')
            {
                temp1begin = j;
                break;
            }
        }
        for (int j = line1[i].length(); j >= 0; j--)
        {
            if (line1[i][j] != ' ')
            {
                temp1end = j;
                break;
            }
        }
        int temp2begin, temp2end;
        for (int j = 0; j < line2[i].length(); j++)
        {
            if (line2[i][j] != ' ')
            {
                temp2begin = j;
                break;
            }
        }
        for (int j = line2[i].length(); j >= 0; j--)
        {
            if (line2[i][j] != ' ')
            {
                temp2end = j;
                break;
            }
        }
        if ((temp2end - temp2begin) != (temp1end - temp1begin))
            return false;
        else
        {
            for (int q = 0; q < (temp2end - temp2begin); q++)
            {
                if (line1[i][temp1begin + q] != line2[i][temp2begin + q])
                    return false;
            }
        }
    }
    if (x == 1)
    {
        rep(i, (x1 - min(x1, x2)), x1)
        {
            if (line1[i] != "")
                return false;
        }
    }
    if (x == 2)
    {
        rep(i, (x2 - min(x1, x2)), x2)
        {
            if (line2[i] != "")
                return false;
        }
    }
    return true;
}
int main()
{
    FastIO;

    return 0;
}