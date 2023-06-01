#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> h(n);

    for(int i=0;i<n;i++) cin >> h[i];

    int total = 0;
    for(int i=0;i<n;i++){
        if(h[i] == 0){
            if(i == 0) total += h[i+1];

            else if(i == n-1) total += h[i-1];

            else total += min(h[i-1], h[i+1]);
        }
    }
    cout << total << '\n';
    return 0;
}
