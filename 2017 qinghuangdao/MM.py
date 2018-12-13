two = [0, 1]
for i in range(1, 3300):
	two.append(two[i]+two[i])
	
T = int(raw_input())
cnt = 1
while cnt <= T:
	cnt = cnt + 1
	ans = 0
	n, m = map(int, raw_input().split(' '))
	if n%m==0:
		print(int(n/m))
		continue
	res = n
	l = 0 
	r = 3300
	while l <= r:
		mid = (l+r)/2
		if (two[mid]-1) * m >= res:
			r = mid-1
		else:
			l = mid+1
	for i in range(l+1, 1, -1):
		if (two[i]-1) * m >= res and res > (two[i-1]-1)*m :
			res = max(res - m * two[i-1], res % two[i-1])
			ans = ans + two[i-1]
			if res == 0:
				break
	print(ans)
	