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

int mxN = 5e5 + 10;

vector<vector<int>> g(mxN);
vector<bool> visited(mxN);

vector<int> answer(mxN);

vector<int> bfs(int node) {
    /* print("BFS"); */
    /* print(node); */
  vector<int> output;

  queue<int> q;
  q.push(node);

  while (!q.empty()) {
    auto x = q.front();
    q.pop();

    output.push_back(x);
    visited[x] = true;

    for (auto i : g[x]) {
      if (!visited[i]) {
        q.push(i);
      }
    }
  }

  return output;
}

void solve() {
  int n, m;
  cin >> n >> m;

  for (auto i = 0; i < m; ++i) {
    int k;
    cin >> k;

    if (k == 0 ) {
      continue;
    }

    int x;
    cin >> x;

    for(auto i = 0; i < k - 1;++i){
      int y;
      cin >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
  }
  for (auto i = 1; i <= n; ++i) {
    /* print("Visited"); */
    /* print(visited.begin() + 1, visited.begin() + 1 + n); */
    if (!visited[i]) {
      auto ls = bfs(i);
      /* print(ls.begin(),ls.end()); */
      auto cnt = ls.size();

      for (auto j : ls) {
        answer[j] = cnt;
      }
    }
  }

  print(answer.begin() + 1, answer.begin() + 1 + n);
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
