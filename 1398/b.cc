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

  set<int> a;

  int n = s.size();

  print(s);
  for (auto i = 0; i < n; ++i) {
    if (s[i] == '1') {
      print(i);
      int cnt = 0;
      for (auto j = i; j < n; ++j) {
        if (s[i] == '0') {
          break;
        }
        ++cnt;
      }

      print("cnt");
      print(cnt); a.insert(cnt);
      i += cnt - 1;
    }
  }

  print(a.size());
  print("");
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
