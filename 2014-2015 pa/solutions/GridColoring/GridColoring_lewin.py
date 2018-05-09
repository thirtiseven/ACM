import sys

n,m = map(int, raw_input().split())

s = [raw_input() for __ in range(n)]

dp = [0 for __ in range(n+1)]
dp[n] = 1
for j in range(m):
	ndp = [0 for __ in range(n+1)]

	big = 0
	for i in range(n):
		if s[i][j] == 'B':
			big = i+1
	small = n
	for i in range(n-1,-1,-1):
		if s[i][j] == 'R':
			small = i

	for i in range(n,-1,-1):
		if i<n:
			dp[i] += dp[i+1]
		if i >= big and i <= small:
			ndp[i] = dp[i]
	dp = ndp

print sum(dp)