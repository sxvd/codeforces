#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

template <typename T> inline void print(T val) { cout << val << '\n'; }

template <typename Iterator> inline void print(Iterator begin, Iterator end) {
  for (auto it = begin; it != end; it = next(it)) {
    cout << *it << ' ';
  }
  cout << '\n';
}

void solve() {
  vector<int> x(4);
  int odd = 0;
  for (auto &i : x) {
    cin >> i;
    if (i & 1) {
      ++odd;
    }
  }

  if (odd <= 1) {
    print("Yes");
    return;
  }

  int r = x[0], g = x[1], b = x[2], w = x[3];

  if (*min_element(x.begin(), x.end()) <= 0) {
    print("No");
    return;
  }
  odd = 0;

  for (auto &i : x) {
    --i;
    if (i & 1) {
      ++odd;
    }
  }

  if (odd <= 1) {
    print("Yes");
    return;
  }

  print("No");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int cases;
  cin >> cases;

  while (cases--) {
    solve();
  }

  return 0;
}
