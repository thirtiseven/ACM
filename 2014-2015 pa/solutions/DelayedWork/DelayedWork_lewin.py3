k,p,x = map(int, input().split())

s = 1
while x * s * (s + 1) <= k * p:
	s += 1

print("%.3f" % (k * p / float(s) + s * x))