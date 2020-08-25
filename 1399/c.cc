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

  vector<int> w(n);
  map<int, int> cnt;
  for (auto &i : w) {
    cin >> i;
    cnt[i]++;
  }

  int ans = 0;
  set<int> done;

  for (auto s = 2; s <= 2 * n; ++s) {
    done.clear();
    int total = 0;
    for (auto i = 1; i <= n; ++i) {
      if (done.count(i)) {
        continue;
      }
      int j = s - i;

      done.insert(i);
      done.insert(j);

      if (i == j) {
        total += cnt[j] / 2;
        continue;
      }

      total += min(cnt[i], cnt[j]);
    }

    ans = max(ans, total);
  }

  print(ans);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  /* freopen("output.txt", "w", stdout); */
#endif

  int cases;
  cin >> cases;

  while (cases--) {
    solve();
  }

  return 0;
}
