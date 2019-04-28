T = int(raw_input())
for i in range(0, T):
	ans = 0
	n = int(raw_input())
	x = 2
	while x <= n:
		ans = ans + int(n/x)
		x = x*2
	print(ans)