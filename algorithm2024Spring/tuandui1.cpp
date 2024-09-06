#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(const vector<vector<int>>&matrix,const int target, int rows, int cols, int row,int col)
{
	int midcol,midrow;
	midcol = (col + cols) / 2;
	midrow = (row + rows) / 2;
	if (rows == row && cols == col && matrix[row][col] != target)
	{
		return false;
	}
	else
	{
		if (matrix[midrow][midcol] == target)
		{
			return true;
		}
		else if (matrix[midrow][midcol] < target)
		{
			return(searchMatrix(matrix, target, midrow, midcol, row, col));
		}
		else
		{
			return(searchMatrix(matrix, target, row, col, midrow, col) || searchMatrix(matrix, target, row, col, row, midcol));
		}
	}
}

int main()
{
	int nums;
	int m, n,target;
	cin >> nums;
	vector<vector<int>>matrix;
	while (nums--)
	{
		cin >> m >> n >> target;
		matrix.resize(m);
		for (int i = 0; i < m; i++)
		{
			matrix[i].resize(n);
			for (int j = 0; j < n; j++)
			{
				cin >> matrix[i][j];
			}
		}
		if (searchMatrix(matrix, target, m, n, 0, 0))
			cout << "true" << endl;
		else cout << "false" << endl;
	}
}