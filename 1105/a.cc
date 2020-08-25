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
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  const int INF = 1e9 + 10;

  int cost = INF;
  int best = -1;

  for (auto t = 1; t <= 150; ++t) {
    int k = 0;
    for (auto i = 0; i < n; ++i) {
      int z = min({abs(t + 1 - a[i]), abs(t - a[i]), abs(t - 1 - a[i])});
      k += z;
    }

    if (k < cost) {
      best = t;
      cost = k;
    }
  }

  print(best);
  print(cost);
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
