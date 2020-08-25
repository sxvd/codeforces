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

  sort(a.begin(), a.end());
  bool ok = true;

  for (auto i = 0; i < n - 1; ++i) {
    if (abs(a[i] - a[i + 1]) > 1) {
      ok = false;
      break;
    }
  }

  print((ok ? "YES" : "NO"));
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
