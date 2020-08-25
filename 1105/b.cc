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
  string s;
  cin >> n >> k;
  cin >> s;

  map<char, int> g;

  for (auto i = 0; i < n; ++i) {
    auto x = s[i];
    auto y = i + 1;
    int cnt = 1;

    for (; y < n; ++y) {
      if (s[y] != x || cnt == k) {
        break;
      }
      ++cnt;
    }

    if (cnt == k) {
      g[x]++;
    }

    i = y;
    --i;
  }

  int ans = 0;

  for(auto i: g){
    ans = max(ans,i.second);
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
