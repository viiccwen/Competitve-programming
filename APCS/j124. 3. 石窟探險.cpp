#include <iostream>
using namespace std;
long long int dis = 0;
void traversal(int root) {
    long long int next_root;
    cin >> next_root;
    
    if (next_root != 0) {
        dis += abs(root - next_root);

        if (next_root % 2 == 0)  // two children
            for (int i = 0; i < 2; i++) traversal(next_root);

        else                    // three children
            for (int i = 0; i < 3; i++) traversal(next_root);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long int root = 0;

    cin >> root;
    if (root != 0) {
        if (root % 2 == 0)  // two children
            for (int i = 0; i < 2; i++) traversal(root);
        
        else  // three children
            for (int i = 0; i < 3; i++) traversal(root);
    }

    cout << dis;
    return 0;
}
