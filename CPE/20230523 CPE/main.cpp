#include <bits/stdc++.h>
using namespace std;

vector<int> Next(string &p) {
  int pLen = p.size();
  vector<int> next(pLen);
  int iPart = 0, iWhole = iPart - 1;

  next[0] = -1;
  while (iPart < pLen) {
    if (iWhole == -1 || p[iPart] == p[iWhole]) {
      iPart++, iWhole++;
      next[iPart] = iWhole;
    } else
      iWhole = next[iWhole];
  }

  return next;
}

int kmp(string &s, string &p) {
  int sI = 0, pI = 0;
  int sLen = s.size(), pLen = p.size();
  vector<int> next = Next(p);

  for (auto i : next) cout << i << ' ';
  cout << '\n';

  while (sI < sLen && pI < pLen) {
    if (pI == -1 || s[sI] == p[pI])
      sI++, pI++;
    else
      pI = next[pI];
  }

  if (pI >= pLen)
    return sI - pLen;
  else
    return -1;
}

void solve() {
  string s = "abcabcabcabe";
  string t = "abcabe";
  cout << kmp(s, t);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}

/*
7 9
5
DR 2 1 5
DC 4 3 6 7 9
IC 1 3
IR 2 2 4
EX 1 2 6 5
4
4 8
5 5
7 8
6 5
0 0

2 2
1
EX 1 1 2 2
0 0

2 2
1
IR 1 1
0 0
*/

/*
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> table;
vector<vector<int>> table_original;
int r, c, cnt, spreadsheet_num = 1;
int ope_num, qry_num;

void Exchange(int &x1, int &y1, int &x2, int &y2) {
  swap(table[x1][y1], table[x2][y2]);
}

void Delete(char &pos, vector<int> &tmp) {
  if (pos == 'R') {
    for (int i = 0; i < tmp.size(); i++) {
      table.erase(table.begin() + tmp[i]);
    }
  } else {
    for (int i = 0; i < tmp.size(); i++)
      for (int j = 1; j <= r; j++) table[j].erase(table[j].begin() + tmp[i]);
  }
}

void Insert(char &pos, vector<int> &tmp) {
  if (pos == 'R') {
    for (int i = 0; i < tmp.size(); i++) {
      vector<int> tmp2(c + 1, 0);
      for (int j = 1; j <= c; j++) tmp2[j] = cnt++;
      table.insert(table.begin() + tmp[i], tmp2);
    }
  } else {
    for (int i = 0; i < tmp.size(); i++)
      for (int j = 1; j <= r; j++)
        table[j].insert(table[j].begin() + tmp[i], cnt++);
  }
}

void Select(char &ope, char &pos) {
  if (ope == 'E') {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Exchange(x1, y1, x2, y2);

  } else if (ope == 'D') {
    int num;
    cin >> num;
    vector<int> tmp(num);
    for (int i = 0, cur; i < num; i++) cin >> tmp[i];

    sort(tmp.begin(), tmp.end());
    Delete(pos, tmp);

  } else if (ope == 'I') {
    int num;
    cin >> num;
    vector<int> tmp(num);
    for (int i = 0, cur; i < num; i++) cin >> tmp[i];

    sort(tmp.begin(), tmp.end());
    Insert(pos, tmp);
  }
}

void Query(int &x, int &y) {
  bool flag = false;
  int aft_x, aft_y;
  for (int i = 1; i < table.size(); i++) {
    for (int j = 1; j < table[0].size(); j++) {
      if (table_original[x][y] == table[i][j]) {
        flag = true;
        aft_x = i;
        aft_y = j;
        break;
      }
    }
  }

  if (flag == false)
    printf("Cell data in (%d,%d) GONE\n", x, y);
  else
    printf("Cell data in (%d,%d) moved to (%d,%d)\n", x, y, aft_x, aft_y);
}

void solve() {
  cin >> r >> c;
  while (r != 0 || c != 0) {
    table.assign(52, vector<int>(52, 0));
    table_original.assign(52, vector<int>(52, 0));
    cnt = 0;

    cin >> ope_num;

    for (int i = 1; i <= r; i++)
      for (int j = 1; j <= c; j++) table[i][j] = cnt++;

    table_original = table;

    for (int i = 0; i < ope_num; i++) {
      char pos, ope;
      cin >> ope >> pos;
      Select(ope, pos);
    }

    printf("Spreadsheet #%d\n", spreadsheet_num++);

    for (int i = 0; i <= r; i++) {
      for (int j = 0; j <= c; j++) {
        cout << table_original[i][j] << ' ';
      }
      cout << '\n';
    }

    cout << "\n \n";

    for (int i = 1; i < table.size(); i++) {
      for (int j = 1; j < table[0].size(); j++) {
        cout << table[i][j] << ' ';
      }
      cout << '\n';
    }

    // cin >> qry_num;
    // for (int i = 0, x, y; i < qry_num; i++) {
    //   cin >> x >> y;
    //   Query(x, y);
    // }

    cin >> r >> c;
    if (r != 0 || c != 0) cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}


*/