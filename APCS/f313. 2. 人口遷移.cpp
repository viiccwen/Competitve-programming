/*
https://zerojudge.tw/ShowProblem?problemid=f313
每天每個城市會向每個它相鄰的城市遷移 人/k個人
第一行，輸出在 m 天之後，人數最少的城市的人數。
第二行，輸出在 m 天之後，人數最多的城市的人數。
*/
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <utility>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int row, column, k, day, minp = INT_MAX, maxp = INT_MIN;
	vector<vector<int>> city;
	pair<int, int> dir[] = { {-1,0},{1,0},{0,-1},{0,1} };
	cin >> row >> column >> k >> day;

	city.resize(row);
	for (int i = 0; i < row; i++) city[i].resize(column);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++)
			cin >> city[i][j];
	}
	vector<vector<int>> temp = city;
	for (int i = 0; i < day; i++) {
		for (int j = 0; j < row; j++) {
			for (int g = 0; g < column; g++) {
				if (city[j][g] != -1) {
					for (int d = 0; d < 4; d++) {
						int nx = j + dir[d].first, ny = g + dir[d].second;
						if (nx >= 0 && nx < row && ny >= 0 && ny < column && city[nx][ny] != -1) {
							temp[nx][ny] += city[j][g] / k;
							temp[j][g] -= city[j][g] / k;
						}
					}
				}
			}
		}
		city = temp;
	}

	for (int i = 0; i < row; i++) {
		for (auto j : city[i]) {
			if (j != -1)
				maxp = max(maxp, j), minp = min(minp, j);
		}
	}
	cout << minp << '\n' << maxp;
}
