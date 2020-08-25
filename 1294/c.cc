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

set<int> f(int n) {
  set<int> output;
  int cnt = 0;

  int x = n;

  for (auto i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      ++cnt;
      n /= i;
      output.insert(i);

      if (cnt == 2) {
        break;
      }
    }
  }

  if (cnt == 2) {
    output.insert(x / *output.begin() / *next(output.begin()));
  }
  return output;
}

void solve() {
  int n;
  cin >> n;

  auto factors = f(n);
  if (factors.size() < 3) {
    print("NO");
    return;
  }
  print("YES");
  print(factors.begin(), factors.end());

  int a, b, c;
  a = b = c = 1;

  /* printf("YES\n"); */
  /* printf("%d %d %d\n",a,b,c ); */
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
