#include <iostream>
#include <vector>
using namespace std;

struct dice {
    int top, down, front, back, left, right;
};

vector<dice> dices(21, { 1,6,4,3,5,2 });

void turn_front(int a) {
    dice& x = dices[a];
    x = { x.back, x.front, x.top, x.down, x.left, x.right };
}

void turn_right(int a) {
    dice& x = dices[a];
    x = { x.left, x.right, x.front, x.back, x.down, x.top };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (a > 0 && b > 0) swap(dices[a], dices[b]);
        else if (b == -1)  turn_front(a);
        else if (b == -2) turn_right(a);
    }
    for (int i = 1; i <= n; i++) {
        cout << dices[i].top << ' ';
    }
    return 0;
}
