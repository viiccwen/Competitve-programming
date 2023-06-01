#include <bits/stdc++.h>
using namespace std;
int n, m;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;

    vector <int> preindex(n);
    for (int i = 0, tot; i < n; i++){
        if(!i)
            cin >> preindex[0];
        else{
            cin >> tot;
            preindex[i] = preindex[i-1] + tot;
        }
    }

    int s = 0;
    for (int i = 0, q; i < m; i++){
        cin >> q;
        if (s != 0) q += preindex[s-1];
        if (q > preindex[n-1]) q -= preindex[n-1];
        s = (int)(lower_bound(preindex.begin(), preindex.end(), q)-preindex.begin())+1;
        s %= n;
    }
    cout << s << '\n';
}
