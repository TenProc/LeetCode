// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <vector>

using namespace std;



bool MySearchMatrix(vector<vector<int>>& matrix, int target)
{
	for (vector<vector<int>>::iterator it = matrix.begin(); it != matrix.end(); it++)
	{
		vector<int> row = *it;

		if (row.size() > 0)
		{
			if (row[row.size() - 1] >= target)
			{
				for (vector<int>::iterator rowIt = row.begin(); rowIt != row.end(); rowIt++)
				{
					if (*rowIt == target)
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}

bool IdealSearchMatrix(vector<vector<int>>& matrix, int target)
{
	int m = matrix.size();
	int n = matrix[0].size();
	int r = m * n - 1;
	int l = 0;
	while (l != r)
	{
		int mid = (l + r) >> 1;
		if (matrix[mid / m][mid % m] < target)
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}

	return matrix[r / m][r % m] == target;
}
void GetSampleData(vector<vector<int>>& matrix)
{
	vector<int>* t = new vector<int>();
	t->push_back(1); t->push_back(3); t->push_back(5); t->push_back(7);
	matrix.push_back(*t);

	t = new vector<int>();
	t->push_back(10); t->push_back(11); t->push_back(16); t->push_back(20);
	matrix.push_back(*t);

	t = new vector<int>();
	t->push_back(23); t->push_back(30); t->push_back(34); t->push_back(50);
	matrix.push_back(*t);
}

int main()
{
	vector<vector<int>> matrix;
	GetSampleData(matrix);
	bool b = MySearchMatrix(matrix, 3);
	return 0;
}