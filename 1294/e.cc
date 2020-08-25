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

  int ans = 0;

  int a[n + 1][m + 1];
  memset(a, 0, sizeof(a));

  for (auto i = 0; i < n; ++i) {
    for (auto j = 0; j < m; ++j) {
      cin >> a[i][j];
      --a[i][j];
    }
  }

  for (auto j = 0; j < m; ++j) {
    vector<int> cnt(n);
    for (auto i = 0; i < n; ++i) {
      if (a[i][j] % (m) == j) {
        int pos = a[i][j] / m;
        if (pos < n) {
          cnt[(i - pos + n) % n]++;
        }
      }
    }

    /* print(cnt.begin(), cnt.end()); */
    int k = n;
    for (auto i = 0; i < n; ++i) {
      k = min(k, n - cnt[i] + i);
    }

    ans += k;
  }
  print(ans);
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
