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
  int b, p, f;
  cin >> b >> p >> f;

  int h, c;
  cin >> h >> c;

  int ans = 0;

  if (h < c) {
    swap(p, f);
    swap(h, c);
  }

  // h > c
  int cnt = min(b / 2, p);
  ans += h * cnt;
  b -= 2 * cnt;

  if(b > 0){
    int z = min(b/2,f);
    ans += c * z;
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
