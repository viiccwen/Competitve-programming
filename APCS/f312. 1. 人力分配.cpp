// https://zerojudge.tw/ShowProblem?problemid=f312

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, A[2], B[2], C[2], maxpro = INT_MIN;

	for (int i = 0; i < 2; i++)
		cin >> A[i] >> B[i] >> C[i];
	cin >> n;
	/*
	3:  0,3 1,2 2,1 3,0 
	4:  0,4 1,3 2,2 3,1 4,0 
	5:  0,5 1,4 2,3 3,2 4,1 5,0  -> ¦@ n+1 ¦¸
	*/

	for (int i = 0; i < n + 1; i++) // i: x1 , n-i: x2
		maxpro = max(maxpro, (A[0] * i * i + B[0] * i + C[0]) + (A[1] * (n - i) * (n - i) + B[1] * (n - i) + C[1]));
	// Y0 = A[0] * i * i + B[0] * i + C[0], Y1 = A[1] * (n - i) * (n - i) + B[1] * (n - i) + C[1]

	cout << maxpro;
}
