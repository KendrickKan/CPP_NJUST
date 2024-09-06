#include<iostream>
#include<vector>
using namespace std;
int a[1001][1001] = {0};
int cnt_empty = 0;
int cnt_numNoEmpty = 0;
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int judge = 0;
			for (int k = -1; k < 2; k++)
			{
				for (int q = -1; q < 2; q++)
				{
					if (i + k >= 0 && j + q >= 0 && (k != 0 || q != 0) && i + k < n && j + q < m)
					{
						if (a[i + k][j + q] == 1) judge = 1;
						//cout <<i<<" "<<j<<" "<<k<<" "<<q<<" "<< a[i + k][j + q]<<" "<<judge;
						//system("pause");
					}
				}
			}
			if (a[i][j] == 0 && judge == 0) a[i][j] = 3;//空格
			if (a[i][j] == 0 && judge == 1) a[i][j] = 2;//数字
		}
	}
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int judge = 0;
			if (a[i][j] == 2)
			{
				for (int k = -1; k < 2; k++)
				{
					for (int q = -1; q < 2; q++)
					{
						if (i + k >= 0 && j + q >= 0 && (k != 0 || q != 0) && i + k < n && j + q < m)
						{
							if (a[i + k][j + q] == 3) {judge = 1; break;}
						}
					}
				}
				if (judge == 0) cnt_numNoEmpty++;//ͳ����Χ�˸�û�С��ո񡱵ġ����֡�����
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 3)
			{
                a[i][j] = -1;
				vector<pair<int,int>>v;
				for (int k = -1; k < 2; k++)
				{
					for (int q = -1; q < 2; q++)
					{
						if (i + k >= 0 && j + q >= 0 && (k != 0 || q != 0) && i + k < n && j + q < m)
						{
							if (a[i + k][j + q] == 3)
							{
								v.push_back({i+k,j+q});
								a[i + k][j + q] = -1;
							}
						}
					}
				}
				while (!v.empty())
				{
					int f = v.back().first;
					int s = v.back().second;
                    a[f][s] = -1;
					v.pop_back();
					for (int k = -1; k < 2; k++)
					{
						for (int q = -1; q < 2; q++)
						{
							if (f + k >= 0 && s + q >= 0 && (k != 0 || q != 0) && f + k < n && s + q < n)
							{
								if (a[f + k][s + q] == 3)
								{
									v.push_back({ f + k,s + q });
									a[f + k][s + q] = -1;
								}
							}
						}
					}
				}
				cnt_empty++;
			}

		}
	}
    // cout << cnt_empty << " " << cnt_numNoEmpty << endl;
	int res = cnt_empty + cnt_numNoEmpty;
	cout << res << endl;
	return 0;
}