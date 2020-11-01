#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int h, w;
    char a[55][55];
    while (cin >> h >> w && (h || w))
    {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> a[i][j];
        string str;
        cin >> str;
        int ans = 0;
        int chux, chuy;
        int houx, houy;
        chux = chuy = houx = houy = 0;
        for (int q = 0; q < str.length(); q++)
        {
            for (int i = 0; i < h; i++)
                for (int j = 0; j < w; j++)
                    if (str[q] == a[i][j])
                        houx = i, houy = j;
            ans += abs(chux - houx) + abs(chuy - houy) + 1;
            chux = houx, chuy = houy;
        }
        cout << ans << endl;
    }

    return 0;
}