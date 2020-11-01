#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxnum 100010
struct people
{
    ll time;
    ll choosejob;
};
people a[maxnum];
ll b[maxnum];
bool cmp(people a, people b)
{
    return a.time < b.time;
}
int main()
{
    ios::sync_with_stdio(false);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].choosejob;
        b[a[i].choosejob]++;
    }
    for (int i = 0; i < n; i++)
        cin >> a[i].time;
    sort(a, a + n, cmp);
    ll sum = 0;
    ll temp = 0;
    for (int i = 1; i <= k; i++)
    {
        if (b[i] == 0)
        {
            for (int j = temp; j < n; j++)
            {
                if (b[a[j].choosejob] > 1)
                {
                    b[a[j].choosejob]--;
                    sum += a[j].time;
                    temp = j + 1;
                    break;
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}