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
  int n, d, m;
  cin >> n >> d >> m;

  vector<int> a(n);
  vector<int> big, small;

  for (auto &i : a) {
    cin >> i;
    if (i > m) {
      big.push_back(i);
    } else {
      small.push_back(i);
    }
  }

  sort(big.rbegin(), big.rend());
  sort(small.rbegin(), small.rend());

  print(big.begin(), big.end());

  int ans = 0;

  for (auto x = 0; x <= n; ++x) {
    ll days = (x - 1) * (d + 1) + 1;
    int sum = 0;
    print(x);
    print(days);
    print("");
    if (days > n) {
      break;
    }

    ans = max(ans, sum);
  }

  print("");
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
