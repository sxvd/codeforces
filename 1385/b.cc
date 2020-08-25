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

  vector<int> a(2 * n);
  for (auto &i : a) {
    cin >> i;
  }
  
  /* print(a.begin(),a.end()); */

  set<int> k;
  vector<int> ans;
  for (auto i = 0; i < 2 * n; ++i) {
    if (!k.count(a[i])) {
      ans.push_back(a[i]);
    }
    k.insert(a[i]);
  }

  print(ans.begin(), ans.end());
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
