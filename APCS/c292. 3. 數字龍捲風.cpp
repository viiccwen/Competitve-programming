#include <iostream>

using namespace std;

int main()

{

    ios_base::sync_with_stdio(false); cin.tie(0);

    int n[2510] = { 0 };
    int x, z, count = 1, change = 2;

    cin >> x >> z;

    for (int i = 1; i <= x * x; i++) cin >> n[i];
    int current = x * (x / 2) + (x / 2) + 1;
    cout << n[current];
    int direct[4] = { -1 , -x , 1 , x };
    for (int j = (x + x) - 2; j > 0; j--) {
        for (int i = count; i > 0; i--) {
            if (z == 0) current += direct[0];
            else if (z == 1) current += direct[1];
            else if (z == 2) current += direct[2];
            else current += direct[3];
            cout << n[current];
        }
        z++;
        if (z > 3) z = 0;
        change--;
        if (change == 0) {
            count++;
            change = 2;
        }
    }
    for (int k = count - 1; k > 0; k--) {
        current += direct[z];
        cout << n[current];
    }
}
