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
const ll MOD = 998244353;
void reduce(ll &a) {
  a %= MOD;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  ll dp[n + 1][k + 1];
  memset(dp, 0, sizeof(dp));
  dp[1][0] = m;

  for (auto i = 2; i <= n; ++i) {
    for (auto j = 0; j <= k; ++j) {
      dp[i][j] = dp[i - 1][j];

      if (j > 0) {
        dp[i][j] += (m - 1) * dp[i - 1][j - 1];
      }

      reduce(dp[i][j]);
    }
  }

  print(dp[n][k]);
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
