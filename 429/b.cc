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
  int n, m;
  cin >> n >> m;

  int mxN = 1e3 + 10;

  int a[mxN][mxN];

  for (auto i = 1; i <= n; ++i) {
    for (auto j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }

  ll dp[2][mxN][mxN], x[mxN][mxN], y[mxN][mxN];
  memset(dp, 0, sizeof(dp));
  memset(x, 0, sizeof(x));
  memset(y, 0, sizeof(y));

  for (auto i = 1; i <= n; ++i) {
    for (auto j = 1; j <= m; ++j) {
      x[i][j] = max(x[i - 1][j], x[i][j - 1]);
    }
  }

  for (auto i = n; i >= 1; --i) {
    for (auto j = 1; j <= m; ++j) {
      x[i][j] = max(x[i + 1][j], x[i][j - 1]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  solve();

  return 0;
}
