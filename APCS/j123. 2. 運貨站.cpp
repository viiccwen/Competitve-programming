#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
vector<vector<int>> box(35,vector<int>(55,0));
int r, c, n, topdis, x, y;
int space = 0, abandon = 0;
char t;
bool break_flag = false;
void simulate() {
    int count = 0;
    x = -1, y = -1;
    if (t == 'A') {
        for (int j = c - 1; j >= 0; j--) {
            for (int i = 0; i < 4; i++) {
                if (box[i + topdis][j] == 1) {
                    x = topdis, y = j + 1;
                    break_flag = true;
                    break;
                }
            }
            if (break_flag) {
                break_flag = false;
                break;
            }
        }
        if (y < c) {
            if (x == -1 && y == -1) x =topdis, y = 0;

            for (int i = 0; i < 4; i++) {
                box[x + i][y] = 1;
            }
            space -= 4;
        }
        else{
            abandon++;
        }
    }

    else if (t == 'B') {
        for (int j = c - 1; j >= 0; j--) {
            if (box[topdis][j] == 1) {
                x = topdis, y = j + 1;
                break;
            }
        }
        if (y + 2 < c) {
            if (x == -1 && y == -1) x = topdis, y = 0;

            for (int i = 0; i < 3; i++) {
                box[x][y+i] = 1;
            }
            space -= 3;
        }
        else {
            abandon++;
        }
    }

    else if (t == 'C') {
        for (int j = c - 1; j >= 0; j--) {
            for (int i = 0; i < 2; i++) {
                if (box[i + topdis][j] == 1) {
                    x = topdis, y = j + 1;
                    break_flag = true;
                    break;
                }
            }
            if (break_flag) {
                break_flag = false;
                break;
            }
        }
        if (y + 1 < c) {
            if (x == -1 && y == -1) x = topdis, y = 0;

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    box[x + i][y + j] = 1;
                }
            }
            space -= 4;
        }
        else {
            abandon++;
        }
    }

    else if (t == 'D') {
        for (int j = c - 1; j >= 0; j--) {
            if (box[topdis + 1][j] == 1) {
                x = topdis + 1, y = j + 1;
                break;
            }
            if (box[topdis][j + 2] == 1) {
                x = topdis + 1, y = j + 1;
                break;
            }
        }
        if (y + 2 < c) {
            if (x == -1 && y == -1) x = topdis + 1, y = 0;

            for (int i = 0; i <= 2; i++) {
                box[x][y + i] = 1;
                if (i == 2) box[x - 1][y + i] = 1;
            }
            space -= 4;
        }
        else {
            abandon++;
        }
    }

    else if (t == 'E') {
        for (int j = c - 1; j >= 0; j--) {
            for (int i = 0; i < 2; i++) {
                if (!i && box[topdis][j + 1] == 1) {
                    x = topdis + 1, y = j + 1;
                    break_flag = true;
                    break;
                }
                if (box[i + topdis + 1][j] == 1) {
                    x = topdis + 1, y = j + 1;
                    break_flag = true;
                    break;
                }
            }
            if (break_flag) {
                break_flag = false;
                break;
            }
        }
        if (y + 1 < c) {
            if (x == -1 && y == -1) x = topdis + 1, y = 0;

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    box[x + i][y + j] = 1;
                    if(!i && j) box[x - 1][y + j] = 1;
                }
            }
            space -= 5;
        }
        else {
            abandon++;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> n;
    space = r*c;

    for (int i = 0; i < n; i++) {
        cin >> t >> topdis;
        simulate();

        /*
        cout << '\n';
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << box[i][j] << ' ';
            }
            cout << '\n';
        }
        */
    }
    //cout << '\n';
    cout << space << ' ' << abandon;
    return 0;
}
