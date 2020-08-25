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

const int MOD = 1e8;

void solve() {
  int n1, n2, k1, k2;
  cin >> n1 >> n2 >> k1 >> k2;

  int dp[n1 + 1][n2 + 2][k1 + 1][k2 + 2];
  memset(dp, 0, sizeof(dp));
  for (int f = 0; f <= n1; f++) {
    for (int h = 0; h <= n2; h++) {
      for (int kf = 0; kf <= k1; kf++) {
        for (int kh = 0; kh <= k2; kh++) {
          long long ans = 0;

          if (f + h == 0) {
            dp[f][h][kf][kh] = 1;
            continue;
          }
          if (f > 0 && kf > 0) {
            ans = (ans + dp[f - 1][h][kf - 1][k2]) % MOD;
          }
          if (h > 0 && kh > 0) {
            ans = (ans + dp[f][h - 1][k1][kh - 1]) % MOD;
          }
          dp[f][h][kf][kh] = ans;
        }
      }
    }
  }

  print(dp[n1][n2][k1][k2]);
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
