#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#define LIMIT 50000
using namespace std;

int team[LIMIT];
bool walked[LIMIT];

void Find(int a) {
	if (!walked[a]) {
		walked[a] = true;
		Find(team[a]);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n) {
		unsigned int ans = 0;
		memset(team, 0, sizeof(team));
		memset(walked, 0, sizeof(walked));

		for (int i = 0; i < n; i++)
			cin >> team[i];

		for (int i = 0; i < n; i++) {
			if (!walked[i]) {
				ans++;
				Find(team[i]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
