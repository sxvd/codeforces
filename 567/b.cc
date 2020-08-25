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

  set<int> in, out;

  int ans = 0;
  int cnt = 0;

  for (auto i = 0; i < n; ++i) {
    char c;
    cin >> c;

    int x;
    cin >> x;

    if (c == '+') {
      in.insert(x);
      ++cnt;
      ans = max(ans, cnt);
    }

    if (c == '-') {
      if (in.count(x)) {
        --cnt;
      } else {
        ans = max(ans, ans + 1);
      }

      ans = max(ans, cnt);
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

  solve();

  return 0;
}
