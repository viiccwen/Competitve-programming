#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int m,n;
    string str;
    cin >> m >> n;
    vector<string> eyp_table(m);


    for(int i=0;i<m;i++) cin >> eyp_table[i];
    cin >> str;

    for(int i=m-1;i>=0;i--){
        string Fstr = "";
        int str_last = n-1;
        int oe_num = 0;

        for(int k=0;k<n;k++)
            if(eyp_table[i][k] == '1') oe_num++;

        for(int j=n-1;j>=0;j--){
            if(eyp_table[i][j] == '0')
                Fstr = str[str_last--] + Fstr;

            else
                Fstr += str[str_last--];
        }
        str = Fstr;

        if(oe_num % 2 == 1){
            int first = 0, second;

            if(str.size() % 2 == 0)
                second = str.size() / 2;

            else
                second = str.size() / 2 + 1;

            while(second != n)
                swap(str[first++], str[second++]);
        }
    }
    cout << str << '\n';

    return 0;
}
