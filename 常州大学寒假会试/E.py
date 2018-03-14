n, a0, an, q = map(float, input().split())
while q:
	q = q-1
	l, r = map(float, input().split())
#	ans = (a0*n+(an-a0))*((l+r)*(r-l+1.0))/2.0/n
	aa = (l+r)/2.0*(r+1.0-l)
	ans = a0 * (r+1-l) + (an-a0)/n*aa
	print("%d" % ans)
	
	