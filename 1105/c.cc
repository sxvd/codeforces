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
  int n, l, r;
  cin >> n >> l >> r;

  int mxN = 2e5 + 10;
  const int MOD = 1e9 + 7;

  ll dp[mxN][3];
  memset(dp, 0, sizeof(dp));

  vector<int> cnt(3);

  if (r - l > 1) {
    cnt[l % 3] = (r - l) / 3 + 1;
    cnt[((l % 3) + 1) % 3] = (r - l - 1) / 3 + 1;
    cnt[((l % 3) + 2) % 3] = (r - l - 2) / 3 + 1;
  } else if (r - l == 1) {
    cnt[l % 3] = 1;
    cnt[r % 3] = 1;
  }else{
    cnt[l % 3] = 1;
  }

  print(cnt.begin(), cnt.end());
  dp[0][0] = dp[0][1] = dp[0][2] = 1;

  dp[1][0] = cnt[0];
  dp[1][1] = cnt[1];
  dp[1][2] = cnt[2];

  for (auto i = 2; i <= n; ++i) {
    dp[i][0] =
        dp[i - 1][0] * cnt[0] + dp[i - 1][1] * cnt[2] + dp[i - 1][2] * cnt[1];

    dp[i][1] =
        dp[i - 1][0] * cnt[1] + dp[i - 1][1] * cnt[0] + dp[i - 1][2] * cnt[2];

    dp[i][2] =
        dp[i - 1][0] * cnt[2] + dp[i - 1][1] * cnt[1] + dp[i - 1][2] * cnt[0];
  }

  for (auto i = 0; i <= n; ++i) {
    print(dp[i], dp[i] + 3);
  }

  print(dp[n][0]);
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
