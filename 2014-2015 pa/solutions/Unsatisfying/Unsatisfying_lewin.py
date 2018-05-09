from collections import defaultdict 

INF = 123123123

n,m = map(int, raw_input().split())

fgraph = defaultdict(list)
rgraph = defaultdict(list)
for i in range(m):
	a,b = map(int, raw_input().split())

	fgraph[-a].append(b)
	fgraph[-b].append(a)
	rgraph[b].append(-a)
	rgraph[a].append(-b)

def dfs(s, node, g):
	if node in s: return
	s.add(node)
	for a in g[node]:
		dfs(s, a, g)

f = defaultdict(set)
r = defaultdict(set)
for x in set(fgraph.keys() + rgraph.keys()):
	dfs(f[x], x, fgraph)
	dfs(r[x], x, rgraph)

ans = INF
for i in range(1,n+1):
	if -i in f[i] and i in f[-i]:
		ans = 0
	elif -i in f[i]:
		ans = min(ans, 1)
	else:
		cf = f[i] & f[-i]
		cr = r[i] & r[-i]
		if cf and cr and min(cf) < 0 and max(cr) > 0:
			ans = min(ans, 1)
		elif f[i] and f[-i] and r[i] and r[-i] and min(f[i]) < 0 and min(f[-i]) < 0 and max(r[i]) > 0 and max(r[-i]) > 0:
			ans = min(ans, 2)

print -1 if ans >= INF else ans