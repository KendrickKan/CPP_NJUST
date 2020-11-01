#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
typedef long long ll;
struct blank
{
    int len;
    int num = 0;
};
bool cmp(blank a, blank b)
{
    return a.num > b.num;
}
bool cmp2(blank a, blank b)
{
    return a.len < b.len;
}
int findx(blank a[], int x, int len)
{
    int low = 0;
    int high = len - 1;
    int mid = -1;
    if (len == 0)
        return -1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid].len == x)
            return mid;
        if (a[mid].len < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    blank a[maxn];
    memset(a, 0, sizeof(a));
    int duoshao = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sort(a, a + duoshao, cmp2);
        int y = findx(a, x, duoshao);
        if (y != -1)
            a[y].num++;
        else
        {
            a[duoshao].len = x;
            a[duoshao].num = 1;
            duoshao++;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        char ch;
        int x;
        cin >> ch >> x;
        sort(a, a + duoshao, cmp2);
        if (ch == '+')
        {
            int y = findx(a, x, duoshao);
            if (y != -1)
                a[y].num++;
            else
            {
                a[duoshao].len = x;
                a[duoshao].num = 1;
                duoshao++;
            }
        }
        else
        {
            int y = findx(a, x, duoshao);
            if (y != -1)
                a[y].num--;
        }
        sort(a, a + duoshao, cmp);
        if (a[0].num < 4)
            cout << "NO" << endl;
        else
        {
            a[0].num -= 4;
            int x = a[0].len;
            sort(a, a + duoshao, cmp);
            if (a[0].num >= 4)
                cout << "YES" << endl;
            else
            {
                if (a[1].num < 2)
                    cout << "NO" << endl;
                else
                    cout << "YES" << endl;
            }
            sort(a, a + duoshao, cmp2);
            int y = findx(a, x, duoshao);
            if (y != -1)
                a[y].num += 4;
            sort(a, a + duoshao, cmp);
        }
    }

    return 0;
}