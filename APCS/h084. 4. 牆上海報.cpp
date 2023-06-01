//height do binary search
//width do greedy

#include <bits/stdc++.h>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> h(n), w(k);
    int high, low = 0;

    for(int i=0;i<n;i++){
        cin >> h[i];
        high = max(high, h[i]);
    }
    high++;                     // Or you will get 90% correct

    for(int i=0;i<k;i++)
        cin >> w[i];

    while(high - low > 1){
        int mid = (high + low) / 2; //binary search
        int cnt = 0, now = 0;
        bool m_hight = false;
        for(int i=0;i<n;i++){ // greedy
            if(h[i] >= mid){
                cnt++;
                if(cnt >= w[now]){
                    cnt = 0;  //clear interval
                    now++;
                    if(now == k){ // all posted
                        m_hight = true;
                        break;
                    }
                }
            }
            else cnt = 0;
        }
        if(m_hight) low = mid;
        else high = mid;
    }

    cout << low << '\n';

    return 0;
}
