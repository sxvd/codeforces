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
  ll r, b, k;
  cin >> r >> b >> k;

  if (r < b) {
    swap(r, b);
  }

  /* r >= b; */

  auto x = (r + b - 1) / b;

  if (x > k) {
    print("REBEL");
  } else {
    print("OBEY");
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
