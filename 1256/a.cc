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
  int a, b, n, s;
  cin >> a >> b >> n >> s;

  int l = 0;
  int h = n;

  int ok = false;

  while (l <= h) {
    auto mid = l + (h - l) / 2;
    print(mid);

    if (mid * a + n - mid == s) {
      ok = true;
    } else if (mid * a + n - mid < s) {
      l = mid + 1;
    } else {
      h = mid - 1;
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
