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
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  bool dec = false;
  vector<bool> good(n, false);
  good[n - 1] = true;

  for (auto i = n - 2; i >= 0; --i) {
    if (dec) {
      if (a[i] <= a[i + 1]) {
        good[i] = true;
      } else {
        break;
      }
      continue;
    }

    if (a[i] >= a[i + 1]) {
      good[i] = true;
    } else {
      dec = true;
      good[i] = true;
    }
  }

  /* print(good.begin(), good.end()); */
  print(find(good.begin(),good.end(),true) - good.begin());
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
