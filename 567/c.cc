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
  int n, k;
  cin >> n >> k;

  vector<ll> a(n);
  map<ll, ll> cnt;

  if (k == 1) {
  }

  vector<ll> before(n), after(n);

  for (auto i = 0; i < n; ++i) {
    cin >> a[i];

    if (a[i] % k == 0) {
      before[i] = cnt[a[i] / k];
    }
    ++cnt[a[i]];
  }

  cnt.clear();

  for (auto i = n - 1; i >= 0; --i) {

    if (a[i] % k == 0) {
      after[i] = cnt[a[i] * k];
    }
    ++cnt[a[i]];
  }

  ll ans = 0;

  for (auto i = 0; i < n; ++i) {
    ans += before[i] * after[i];
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
