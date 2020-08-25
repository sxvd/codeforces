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
  vector<int> a(3);
  int n;

  cin >> a[0] >> a[1] >> a[2] >> n;

  sort(a.rbegin(), a.rend());
  n -= (a[0] - a[1]);

  n -= (a[0] - a[2]);

  /* print(n); */

  if (n < 0 || n % 3 != 0) {
    print("NO");
  } else {
    print("YES");
  }
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
