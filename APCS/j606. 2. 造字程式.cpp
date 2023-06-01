#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k, q, r;
    string s1,s2;
    cin >> k >> q >> r;
    vector<string> v(q);
    cin >> s1;
    s2 = s1;
    for (int i = 0; i < q; i++) {
        for (int j = 0, temp; j < k; j++) {
            cin >> temp;
            s2[temp-1] = s1[j];
        }
        s1 = s2;
        v[i] = s1;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < q; j++) {
            cout << v[j][i];
        }
        cout << '\n';
    }
    return 0;
}
