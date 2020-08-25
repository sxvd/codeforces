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
  string s;
  cin >> s;
  s = "R" + s + "R";
  int last = 0;
  int n = s.size();

  const int INF = 1e9 + 5;
  int ans = 0;

  for (auto i = 1; i <= n; ++i) {
    if (s[i] == 'R') {
      ans = max(ans, i - last);
      last = i;
    }
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
