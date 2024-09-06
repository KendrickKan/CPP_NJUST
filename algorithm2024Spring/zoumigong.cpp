#include<iostream>
using namespace std;
int t, n, m;
int start[2], target[2];
char arr[105][105];
bool used[105][105];
bool finish;
bool finishes[10005] = { 0 };
int dirx[4] = { 0,1,0,-1 };
int diry[4] = { 1,0,-1,0 };
bool in(int x, int y)
{
	return x > 0 && y > 0 && x <= m && y <= n;
}
void fun(int x, int y)
{
	if (x == target[1] && y == target[0])
	{
		finish = true;
		return;
	}
	if (!finish)
	{
		for (int i = 0; i < 4; ++i)
		{
			int x0, y0;
			x0 = x + dirx[i];
			y0 = y + diry[i];
			if (in(x0, y0) && arr[y0][x0] != '#' &&  !used[y0][x0])
			{
				used[y0][x0] = true;
				fun(x0, y0);
			}
		}
	}
}

int main()
{
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		cin >> n >> m;
		finish = false;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				cin >> arr[i][j];
				if (arr[i][j] == 'S')
				{
					start[0] = i;
					start[1] = j;
					arr[i][j] = '.';
				}
				if (arr[i][j] == 'G')
				{
					target[0] = i;
					target[1] = j;
					arr[i][j] = '.';
				}
			}
		}
		fun(start[1], start[0]);
		if (finish)
		{
			finishes[k] = true;
		}
	}
	for (int i = 0; i < t; i++)
	{
		if (finishes[i])
		{
			cout << "exist!" << "\n";
		}
		else
		{
			cout << "not exist!" << "\n";
		}
	}
}