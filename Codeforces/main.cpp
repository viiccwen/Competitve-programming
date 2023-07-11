#include <bits/stdc++.h>
#define SIZE 10000
#define Next cout << '\n'
#define lson v << 1 + 1
#define rson v << 1 + 2
using namespace std;

vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int arr_len;
int N;

struct Node {
  int val;
  int tag;
};

vector<Node> seg(SIZE);

int val;

void build(int L = 0, int R = arr_len - 1, int v = 0) {
  if (L == R) {
    seg[v].val = arr[L];
    N = max(N, v);
    return;
  }

  int M = (L + R) >> 1;
  build(L, M, lson);
  build(M + 1, R, rson);
  seg[v].val = seg[lson].val + seg[rson].val;
}

void addtag(int tag, int v) {
  seg[v].val += tag;
  seg[v].tag += tag;
}

void push(int v) {
  addtag(seg[v].tag, lson);
  addtag(seg[v].tag, rson);
  seg[v].tag = 0;
}

void modify(int QL, int QR, int L = 0, int R = arr_len - 1, int v = 0,
            int x = 0) {
  if (QL >= L && QR <= R) {
    addtag(x, v);
    return;
  }

  push(v);
  int M = (L + R) >> 1;
  if (R <= M)
    modify(QL, QR, L, M, lson, x);
  else if (L > M)
    modify(QL, QR, M + 1, R, rson, x);
  else {
    modify(QL, M, L, M, lson, x);
    modify(M + 1, QR, M + 1, R, rson, x);
  }
  seg[v].val = seg[lson].val + seg[rson].val;
}

int query(int QL, int QR, int L = 0, int R = arr_len - 1, int v = 0) {
  if (QL == L && QR == R) return seg[v].val;

  int M = (L + R) >> 1;
  if (R <= M)
    return query(QL, QR, L, M, lson);
  else if (L > M)
    return query(QL, QR, M + 1, R, rson);
  else
    return query(QL, M, L, M, lson) + query(M + 1, QR, M + 1, R, rson);
}

int main() {
  arr_len = arr.size();

  build();
  for (auto i : arr) cout << i << ' ';
  Next;
  for (int i = 0; i < N; i++) cout << seg[i].val << ' ';
}