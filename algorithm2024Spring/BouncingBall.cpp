#include<iostream>
#include<iostream>
using namespace std;
int t = 0;
int main()
{
	cin >> t;
	while (t!=0)
	{
		int n, p, k;//格子数，起始位置，跳跃周期
		cin >> n >> p >> k;
		string str = "";
		cin >> str;
		bool* point = new bool[n];//1合法
		for (int i = 0; i < n; i++)
		{
			if(str[i]=='0')
			{
				point[i] = 0;
			}
			else 
			{
				point[i] = 1;
			}
		}
		int x, y;
		cin >> x >> y;//x改变，y删除
		int* z = new int[k];//花费数组
		for (int i = 0; i < k; i++)//初始化数组Z
		{
			z[i] = 0;
		}
		for (int i = 0; i < k; i++)
		{
			for (int j = p+i-1; j < n; )
			{
				if (!point[j])
				{
					z[i] += x;
				}
				j += k;
			}
		}
		int answer = z[0];//不删
		for (int i = 1; i < (n - p); i++)
		{
			if (!point[p + i-1])
			{
				answer = min(answer , (z[(i%k)] + i * y));
				z[i%k] -= x;
			}
			else
			{
				answer = min(answer, (z[(i%k)] + i * y));
			}
		}
		cout << answer << endl;
		delete [] point;
		delete [] z;
		t--;
	}

	return 0;
}