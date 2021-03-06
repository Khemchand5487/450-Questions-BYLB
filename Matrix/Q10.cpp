/*
Title: Common elements in all rows of a given matrix
Link: https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/
Complexity: TIme - O(r*c), Space - O(c)
*/

#include <bits/stdc++.h>
using namespace std;

#define M 4
#define N 5

// prints common element in all rows of matrix
void printCommonElements(int mat[M][N])
{
	unordered_map<int, int> mp;

	for (int j = 0; j < N; j++)
		mp[mat[0][j]] = 1;

	// traverse the matrix
	for (int i = 1; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (mp[mat[i][j]] == i)
			{
				mp[mat[i][j]] = i + 1;

				if (i==M-1 && mp[mat[i][j]]==M)
				cout << mat[i][j] << " ";
			}
		}
	}
}

int main()
{
	int mat[M][N] =
	{
		{1, 2, 1, 4, 8},
		{3, 7, 8, 5, 1},
		{8, 7, 7, 3, 1},
		{8, 1, 2, 7, 9},
	};

	printCommonElements(mat);

	return 0;
}
