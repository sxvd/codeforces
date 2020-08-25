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
int n;
string s;

int cnt(string x, bool check) {
  int i = 0;
  int c = x.size();

  if (c == 1) {
    return 0;
  }

  map<char, int> mp;
  int mx = 0;
  for (auto i = 0; i < c / 2; ++i) {
    if (!check) {
      mp[x[i]]++;
      mx = max(mx, mp[x[i]]);
    } else {
      mx += (x[i] == 'a' ? 1 : 0);
    }
  }

  int first = c / 2 - mx + cnt(string(x.begin() + c / 2, x.end()), false);

  mp.clear();
  mx = 0;
  for (auto i = c / 2; i < c; ++i) {
    if (!check) {
      mp[x[i]]++;
      mx = max(mx, mp[x[i]]);
    } else {
      mx += (x[i] == 'a' ? 1 : 0);
    }
  }
  int second = c / 2 - mx + cnt(string(x.begin(), x.begin() + c / 2), false);

  if (c == 8) {
    print(x);
    print(first);
  }

  if (!check) {
    return min(first, second);
  }else{
    return first;
  }
}

void solve() {
  cin >> n;

  cin >> s;
  print(cnt(s, true));
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
