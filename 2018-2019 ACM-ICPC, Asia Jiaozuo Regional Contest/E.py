import math

isPrime = [True] * 1000
Prime = []
for i in range(2, 1000):
	if isPrime[i]:
		Prime.append(i)
		for j in range(i * i, 1000, i):
			isPrime[j] = False
			
T = int(input())

while T >= 1:
	T = T-1
	n = int(input())
	cur = 1
	up = 1
	down = 1
	for i in Prime:
		cur *= i
		if cur > n:
			break
		up *= i
		down *= (i + 1)
	gcd = math.gcd(up, down)
	up //= gcd
	down //= gcd
	print(str(up) + '/' + str(down))
	