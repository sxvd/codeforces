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
  int lo = 1, hi = 1e9 + 1;
  int res;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if ((mid - mid / n) >= k) {
      if (mid % n != 0)
        res = mid;
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << res << endl;
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
