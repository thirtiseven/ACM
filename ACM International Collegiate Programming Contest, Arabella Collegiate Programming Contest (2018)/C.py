import math

T = int(input())

for i in range(0, T):
	a, b, c, x = map(float, input().split(' '))
	xx = b*x/100.0
	yy = a*x/100.0
	ans = math.sqrt((b+c+c-xx)*(b+c+c-xx)+(a-yy)*(a-yy))
	ans = ans + math.sqrt(xx*xx+yy*yy)
	ans = ans + math.sqrt(a*a+(b+c+c)*(b+c+c))
	print(ans)
