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

  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
    float x;
    cin >> x;
  }

  /* print(a.begin(), a.end()); */

  vector<int> dp(n, 1);

  for (auto i = 1; i < n; ++i) {
    for (auto j = 0; j < i; ++j) {
      if (a[i] >= a[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  /* print(dp.begin(), dp.end()); */
  print(n - *max_element(dp.begin(), dp.end()));
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
