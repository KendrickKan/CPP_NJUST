#include <bits/stdc++.h>
using namespace std;
struct node
{
    int a;
    int b;
};
bool cmp(node x, node y)
{
    if (x.a == y.a)
    {
        return x.b < y.b;
    }
    else
        return x.a < y.a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int s;
    cin >> s;
    cout << s << ':' << endl;
    node q[1008611];
    int k = 0;
    for (int i = 2; i <= s / 2; i++)
    {
        if (s % i == 0 && s / i != 1)
        {
            q[k].a = i;
            q[k].b = i;
            k++;
        }
    }
    for (int i = 2; (2 * i - 1) <= s; i++)
    {
        if (s % (2 * i - 1) == 0)
        {
            q[k].a = i;
            q[k].b = i - 1;
            k++;
        }
    }
    for (int i = 2; (2 * i - 1) <= (s - i); i++)
    {
        if ((s - i) % (2 * i - 1) == 0)
        {
            q[k].a = i;
            q[k].b = i - 1;
            k++;
        }
    }
    sort(q, q + k, cmp);
    for (int i = 0; i < k; i++)
    {
        cout << q[i].a << ',' << q[i].b << endl;
    }
    return 0;
}