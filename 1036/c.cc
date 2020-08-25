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

ll digits(ll x) {
  vector<int> d;

  while (x > 0) {
    d.push_back(x % 10);
    x /= 10;
  }

  ll ten = 1;
  ll ans = 0;

  int j = d.size();

  reverse(d.begin(),d.end());

  for (auto i = 1; i < j - 1; ++i) {
    ans = ans * 10 + d[i];
  }

  return ans;
}

ll count(ll n) {
  ll ans = 0;

  while (n > 0) {
    ans++;
    n /= 10;
  }

  return ans;
}

ll get(ll n, ll d) {
  if (d <= 0) {
    return 0;
  }

  if (d == 1) {
    return count(n);
  }

  if (n <= 0) {
    return 0;
  }

  print(digits(n));

  return get(digits(n), d - 1) + get(digits(n), d);
}

void solve() {
  print(digits(1024));
  ll l, r;
  cin >> l >> r;

  ll y = get(l - 1, 1);
  ll x = get(r,3 ) +get(r, 2) + get(r, 1);

  print(x - y);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}
