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
  vector<ll> x(n);

  for (auto i = 0; i < n; ++i) {
    cin >> x[i];
  }

  vector<ll> mi(n), mx(n);

  mi[0] = abs(x[0] - x[1]);
  mx[0] = abs(x[0] - x[n - 1]);

  mi[n - 1] = abs(x[n - 1] - x[n - 2]);
  mx[n - 1] = abs(x[0] - x[n - 1]);

  for (auto i = 1; i < n - 1; ++i) {
    mi[i] = min(abs(x[i] - x[i - 1]), abs(x[i] - x[i + 1]));
    mx[i] = max(abs(x[0] - x[i]), abs(x[i] - x[n - 1]));
  }

  for(auto i = 0; i < n; ++i){
    printf("%lld %lld\n", mi[i],mx[i]);
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
