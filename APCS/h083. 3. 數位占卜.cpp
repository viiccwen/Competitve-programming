#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
    int n, sum = 0;
    cin >> n;
    vector<string> s(n);

    for(int i=0;i<n;i++) cin >> s[i];

    sort(s.begin(), s.end());

    for(int i=0;i<n;i++){
        string t = s[i];
        for(int j=1; j*2 < t.size();j++){
            string A = t.substr(0, j);
            string maybe_A = t.substr(t.size()-j);

            if(A != maybe_A) continue;
            else{
                string B = t.substr(j, t.size()-(j*2));
                if(binary_search(s.begin(),s.end(),B))
                    sum++;
            }
        }
    }
    cout << sum << '\n';
    return 0;
}
