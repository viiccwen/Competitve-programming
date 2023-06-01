#include <bits/stdc++.h>
#define MAX 60000
using namespace std;

unsigned int reflect = 0;
vector<vector<pair<int,int>>> store_y(MAX);
vector<vector<pair<int,int>>> store_x(MAX);

int Search(int x, int y, int xy, int sb){ //x:0 y:1    smaller:0 bigger:1
    int result;
    bool flag = false;

    if(!xy){
        if(!sb){
            for(int i=0;i<store_x[y].size();i++){
                if(store_x[y][i].first > x) {;
                    flag = true;
                    result = i;
                    break;
                }
            }
        }
        else{
            for(int i=store_x[y].size()-1;i>=0;i--){
                if(store_x[y][i].first < x) {
                    flag = true;
                    result = i;
                    break;
                }
            }
        }
    }
    else{
        if(!sb){
            for(int i=0;i<store_y[x].size();i++){
                if(store_y[x][i].first > y) {
                    flag = true;
                    result = i;
                    break;
                }
            }
        }
        else{
            for(int i=store_y[x].size()-1;i>=0;i--){
                if(store_y[x][i].first < y) {
                    flag = true;
                    result = i;
                    break;
                }
            }
        }
    }

    if(flag) return result;
    else return -1;
}

int change_status(int orig, int lr){
    if(!lr){
        if(orig == 0) orig = 3;
        else if (orig == 1) orig = 2;
        else if (orig == 2) orig = 1;
        else if (orig == 3) orig = 0;
    }
    else{
        if(orig == 0) orig = 2;
        else if (orig == 1) orig = 3;
        else if (orig == 2) orig = 0;
        else if (orig == 3) orig = 1;
    }

    return orig;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;

    int x, y, t;
    for(int i=0;i<n;i++){
        cin >> x >> y >> t;
        store_x[y+30000].push_back({x,t});
        store_y[x].push_back({y+30000,t});
    }

    for(int i=0;i<MAX;i++){
        if(!store_x[i].empty())                         // sort
            sort(store_x[i].begin(),store_x[i].end());

        if(!store_y[i].empty())
            sort(store_y[i].begin(),store_y[i].end());
    }

    x = 0, y = 30000, t = 3; //initalize (0,30000)
    while(1){
        int index;
        if(t == 0){
            index = Search(x, y, 1, 0); //(x,y)
            if(index == -1) break;
            else{
                reflect++;
                y = store_y[x][index].first;
                t = change_status(t, store_y[x][index].second);
            }
        }
        else if(t == 1){
            index = Search(x, y, 1, 1);
            if(index == -1) break;
            else{
                reflect++;
                y = store_y[x][index].first;
                t = change_status(t, store_y[x][index].second);
            }
        }
        else if(t == 2){
            index = Search(x, y, 0, 1);
            if(index == -1) break;
            else{
                reflect++;
                x = store_x[y][index].first;
                t = change_status(t, store_x[y][index].second);
            }
        }
        else if(t == 3){
            index = Search(x, y, 0, 0);
            if(index == -1) break;
            else{
                reflect++;
                x = store_x[y][index].first;
                t = change_status(t, store_x[y][index].second);
            }
        }
    }

    cout << reflect << "\n";
    return 0;
}
