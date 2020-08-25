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

  vector<pair<int, int>> p(n);

  for (auto &i : p) {
    cin >> i.first >> i.second;
  }

  sort(p.begin(), p.end());

  pair<int, int> cur{0, 0};
  string ans;

  bool ok = true;

  for (auto i = 0; i < n; ++i) {
    int x = p[i].first, y = p[i].second;
    /* ans += string('R', x - cur.first); */
    if(y < cur.second){
      ok = false;
      break;
    }
    ans += string(x - cur.first,'R');
    ans += string(y - cur.second, 'U');
    cur.first = x;
    cur.second = y;
  }

  if(ok){
    print("YES");
    print(ans);
  }else{
    print("NO");
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
