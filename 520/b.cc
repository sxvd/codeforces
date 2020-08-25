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

  if (m < n) {
    print(abs(n - m));
    return;
  }

  int cnt = 0;
  while (2 * n <= m) {
    n *= 2;
    ++ans;
  }
  if (n == m) {
    print(ans);
    return;
  }

  int k = abs(n - m);

  ++ans;
  n *= 2;
  ans += abs(m - n);
  print(min(ans, k));
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
