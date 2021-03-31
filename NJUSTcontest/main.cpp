#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
typedef long long ll;
const int MAXN = 100005;
int a[MAXN];
int k;
int main()
{
	FastIO;
	int t;
	cin >> t;
	while (t--)
	{
		int n, q;
		cin >> n >> q >> k;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			a[i] = x;
		}
		for (int i = 0; i < q; i++)
		{
			int op, l, r;
			cin >> op >> l >> r;
			if (op == 2)
			{
				int sum = 0;
				for (int i = l - 1; i <= r - 1; i++)
				{
					if (a[i] <= k)
						sum++;
				}
				cout << sum << endl;
			}
			else
			{
				for (int i = l - 1; i <= r - 1; i++)
				{
					if (a[i] >= 2 * k)
						a[i] -= k;
				}
			}
		}
	}
	return 0;
}
