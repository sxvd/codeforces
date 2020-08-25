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

  vector<pair<int, int>> a(n);

  map<int, int> x, y;
  map<pair<int, int>, int> z;

  for (auto &i : a) {
    cin >> i.first >> i.second;
    x[i.first]++;
    y[i.second]++;
    z[i]++;
  }

  const int MOD = 998244353;

  int cnt1, cnt2, cnt12;
  cnt1 = cnt2 = cnt12 = 1;

  auto factorial = [](int x) {
    int k = 1;
    for (auto i = 1; i <= x; ++i) {
      k = (k * i);
      if (k > MOD) {
        k -= MOD;
        // FIXME
      }
    }

    return k;
  };

  for (auto i : x) {
    cnt1 *= factorial(i.second);
    if (cnt1 >= MOD) {
      cnt1 -= MOD;
    }
  }
  for (auto i : y) {
    cnt2 *= factorial(i.second);
    if (cnt2 >= MOD) {
      cnt2 -= MOD;
    }
  }
  for (auto i : z) {
    cnt12 *= factorial(i.second);
    if (cnt12 >= MOD) {
      cnt12 -= MOD;
    }
  }

  print(factorial(n) - cnt1 - cnt2 + (cnt12 == 1 ? 0 :cnt12));
  print(factorial(n));
  print(cnt1);
  print(cnt2);
  print(cnt12);
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
