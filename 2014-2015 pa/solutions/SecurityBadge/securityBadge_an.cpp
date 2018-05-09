#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

struct door {
  int dst, lo, hi;
  door(int dst, int lo, int hi) : dst(dst), lo(lo), hi(hi) {}
};

typedef vector<door> VD;

VD adj[1024];
int s, t;

bool visited[1024];

void dfs(int cur, int id) {
  if (visited[cur]) return;
  visited[cur] = true;
  for (auto edge : adj[cur]) {
    if (id >= edge.lo && id <= edge.hi) dfs(edge.dst, id);
  }
}

bool accessible(int id) {
  for (int i = 0 ; i < 1024; i++) visited[i] = false;
  dfs(s, id);
  return visited[t];
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  cin >> s >> t;
  set<int> boundaries;
  for (int i = 1; i <= m; i++) {
    int src, dst, lo, hi;
    cin >> src >> dst >> lo >> hi;
    adj[src].push_back(door(dst, lo, hi));
    boundaries.insert(lo);
    boundaries.insert(hi + 1);
  }
  int last = 0;
  bool lastGood = false;
  int ans = 0;
  for (auto id : boundaries) {
    if (lastGood) ans += id - last;
    lastGood = accessible(id);
    last = id;
  }
  cout << ans << endl;
}
