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

  string s;
  cin >> s;

  int lz = 0, lo = 0;

  vector<int> ans(n + 1, 0);

  vector<int> p[2];
  int k = 0;

  for (auto i = 1; i <= n; ++i) {
    /* dbg(p); */
    int x = s[i - 1] - '0';

    if (p[x].empty()) {
      ++k;
      ans[i] = k;
    } else {
      ans[i] = p[x].back();
      p[x].pop_back();
    }

    p[!x].push_back(ans[i]);
  }

  print(k);
  print(ans.begin() + 1, ans.end());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  /* freopen("output.txt", "w", stdout); */
#endif

  int cases;
  cin >> cases;

  while (cases--) {
    solve();
  }

  return 0;
}
