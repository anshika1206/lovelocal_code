// Question : Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximalSquare(vector<vector<char>> &matrix)
{
	if (matrix.empty())
	{
		return 0;
	}

	int m = matrix.size();
	int n = matrix[0].size();
	int sz = 0;

	vector<vector<int>> dp(m, vector<int>(n, 0));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{

			if (!i || !j || matrix[i][j] == '0')
			{
				dp[i][j] = matrix[i][j] - '0';
			}
			else
			{
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			}

			sz = max(dp[i][j], sz);
		}
	}

	return sz * sz;
}

int main()
{
	int m, n;
	cout << "Enter the number of rows: ";
	cin >> m;
	cout << "Enter the number of columns: ";
	cin >> n;

	vector<vector<char>> matrix(m, vector<char>(n));
	cout << "Enter the matrix elements ('0' or '1'):" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}

	int result = maximalSquare(matrix);

	cout << "The area of the largest square containing only 1s is: " << result << endl;

	return 0;
}
