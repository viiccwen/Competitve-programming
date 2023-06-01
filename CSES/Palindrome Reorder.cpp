#include <bits/stdc++.h>
#include <unordered_map>
#define f first
#define s second
using namespace std;

bool CheckPalindrome(unordered_map<char, int>& mp, const string& str) {
    int len = str.size();

    for (char c : str) mp[c]++;

    if (!(len % 2)) {
        for (auto i : mp) 
            if (i.s % 2 == 1) return false;
    }
    else {
        bool flag = false;
        for (auto i : mp) {
            if (i.s % 2 == 1) {
                if (!flag) flag = true;
                else return false;
            }
        }
    }

    return true;
}

void Reorder(unordered_map<char, int>& mp) {
    int count;
    string res, middle = "";
    vector<pair<char, int>> vmp;
    vector<pair<char, int>>::reverse_iterator ite;

    for (auto i : mp) vmp.push_back({ i.f, i.s });
    
    sort(vmp.begin(), vmp.end(), [](pair<char,int> a, pair<char, int> b) { return a.s > b.s; });

    for (auto& i : vmp) { // 前半段
        if (i.s % 2) {
            for (int j = 0; j < i.s; j++) middle += i.f;
            i.s = 0;
        }
        else {
            count = i.s / 2;
            while (i.s > count) { res += i.f; i.s--; }
        }
    }
    
    res += middle;

    for (ite = vmp.rbegin(); ite != vmp.rend(); ite++) {
        while (ite->s-- > 0) res += ite->f;
    }

    cout << res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    string str;
    unordered_map<char, int> mp;
    cin >> str;

    if (!CheckPalindrome(mp, str)) cout << "NO SOLUTION\n";
    else  Reorder(mp);
   
    return 0;
}