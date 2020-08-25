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
  int q, x;
  cin >> q >> x;

  vector<int> cnt(x, 0);

  int ans = 0;

  for (auto i = 0; i < q; ++i) {
    int p;
    cin >> p;

    p %= x;
    cnt[p]++;

    while (cnt[ans % x]) {
      cnt[ans % x]--;
      ++ans;
    }

    print(ans);
  }
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
