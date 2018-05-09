s = map(int,raw_input())
n = len(s)

INF = 7777777777

def fix(wantcarry, wantval, curcarry, curval):
	want, cur = wantcarry * 10 + wantval, curval + curcarry
	return (cur > want) * INF or (want - cur)

dp = [[[-1 for a in range(2)] for b in range(2)] for c in range(n)]
def solve(p, a1, a2):
	if p == n-p-1: return min(fix(a1, i, a2, s[p]) for i in range(10))
	if p > n-p-1: return (a1 != a2) * INF
	if dp[p][a1][a2] != -1: return dp[p][a1][a2]

	res = INF
	for want in range(10):
		for needcarry in range(2):
			cval = s[n-1-p] + a2
			res = min(res, 
				fix(a1, want, needcarry, s[p]) + 
				(want < cval) * 10 + want - cval + 
				solve(p+1,needcarry,want < cval)
			)

	dp[p][a1][a2] = res
	return res

print min(solve(0,0,0), solve(0,1,0))
