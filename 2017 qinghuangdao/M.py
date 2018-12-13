two = [0, 1]
for i in range(1, 4012):
	two.append(two[i]*2)
one = []
for i in range(0, 4012):
	one.append(two[i] - 1)

T = int(input())
cnt = 1
while cnt <= T:
	cnt = cnt + 1
	ans = 0
	n, m = map(int, input().split(' '))
	res = n
	for i in range(4000, 0, -1):
		if one[i] * m == res:
			ans += one[i]
			break
		elif one[i] * m > res:
			ans += two[i - 1]
			res -= m * two[i - 1]
		else:
			res %= two[i]
			ans += two[i]
	print(ans)
	