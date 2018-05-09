#include <iostream>
#include <map>
#include <vector>
#include <cstdio>

using namespace std;

map<int, vector<int> > adj[50005];
int last[50005];
bool locked[50005];

void mark(int src, int dst) {
  if (locked[dst]) return;
  if (last[dst] == 0) {
    last[dst] = src;
    for (auto entry : adj[dst]) {
      for (auto next : entry.second) {
        if (next != src) mark(dst, next);
      }
    }
  } else if (last[dst] != src) {
    locked[dst] = true;
    mark(dst, last[dst]);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    adj[a][c].push_back(b);
    adj[b][c].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    if (locked[i]) continue;
    for (auto entry : adj[i]) {
      if (entry.second.size() > 1) {
        for (auto next : entry.second) mark(i, next);
      }
    }
  }

  int count = 0;
  for (int i = 1; i <= n; i++) {
    if (last[i] == 0) count++;
  }
  cout << count << endl;
  for (int i = 1; i <= n; i++) {
    if (last[i] == 0) cout << i << endl;
  }
}
