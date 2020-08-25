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

  vector<int> a(n), b(n);

  for (auto &i : a) {
    cin >> i;
  }

  for (auto &i : b) {
    cin >> i;
  }

  int x = *min_element(a.begin(), a.end());
  int y = *min_element(b.begin(), b.end());

  ll ans = 0;

  for (auto i = 0; i < n; ++i) {
    int both = min(a[i] - x, b[i] - y);

    a[i] -= both;
    b[i] -= both;

    ans += both;
    ans += a[i] - x;
    ans += b[i] - y;
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

  int cases;
  cin >> cases;

  while (cases--) {
    solve();
  }

  return 0;
}
