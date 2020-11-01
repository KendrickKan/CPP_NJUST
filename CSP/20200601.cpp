#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int x, y;
    char type;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    node nodelist[1005];
    memset(nodelist, 0, sizeof(nodelist));
    for (int i = 0; i < n; i++)
    {
        cin >> nodelist[i].x >> nodelist[i].y;
        char ch;
        cin >> ch;
        nodelist[i].type = ch;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        char dayu, xiaoyu;
        dayu = xiaoyu = '0';
        for (int j = 0; j < n; j++)
        {
            if ((b * nodelist[j].x + c * nodelist[j].y + a) > 0)
            {
                if (dayu == '0')
                    dayu = nodelist[j].type;
                else
                {
                    if (dayu != nodelist[j].type)
                    {
                        cout << "No" << endl;
                        goto stop;
                    }
                }
            }
            if ((b * nodelist[j].x + c * nodelist[j].y + a) < 0)
            {
                if (xiaoyu == '0')
                    xiaoyu = nodelist[j].type;
                else
                {
                    if (xiaoyu != nodelist[j].type)
                    {
                        cout << "No" << endl;
                        goto stop;
                    }
                }
            }
        }
        cout << "Yes" << endl;
    stop:;
    }
    return 0;
}