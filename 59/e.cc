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

struct c {
  int x, y, z;
};

const int mxN = 3e3 + 10;

vector<vector<int>> g(mxN);
set<array<int, 3>> banned;

const int INF = 1e9 + 7;

int dist[mxN][mxN];

void bfs(int source) {
  queue<pair<int, int>> q;
  q.push({0, source});
  dist[0][source] = 1;

  while (!q.empty()) {
    auto u = q.front();
    q.pop();

    auto y = u.second;

    for (auto v : g[y]) {
      if (!banned.count({u.first, y, v}) && dist[y][v] == 0) {
        dist[y][v] = dist[u.first][y] + 1;
        q.push({y, v});
      }
    }
  }
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  memset(dist, 0, sizeof(dist));
  for (auto i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;

    g[x].push_back(y);
    g[y].push_back(x);
  }

  for (auto i = 0; i < k; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    banned.insert({x, y, z});
  }

  bfs(1);

  int ans = INF, pos = -1, pp = n;

  for (auto i = 0; i < n; ++i) {
    if (dist[i][n] != 0) {
      if (ans > dist[i][n]) {
        ans = dist[i][n];
        pos = i;
      }
    }
  }

  if (ans == INF) {
    print(-1);
    return;
  }

  assert(pos != -1);

  vector<int> p;
  while (pos != 1) {
    p.push_back(pp);
    p.push_back(3); 
    for (auto i : g[pos]) {
      if (!banned.count({i, pos, pp}) && dist[pos][pp] == dist[i][pos] + 1) {
        pp = pos;
        pos = i;
        break;
      }
    }
  }

  reverse(p.begin(), p.end());
  print(ans - 1);

  print(p.begin(), p.end());
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
