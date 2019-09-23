import math
def digitProd(natNumber):
	numberString = str(natNumber)
	digitProd = 1
	for letter in numberString:
		digitProd = digitProd*int(letter)
	return digitProd
def digitSum(natNumber):
	numberString = str(natNumber)
	digitSum = 0
	for letter in numberString:
		digitSum = digitSum * int(letter)
	return digitSum
for n in range(0, 24):
	count = 0
	for a in range(int(math.pow(10, n)), int(math.pow(10, n+1))):
		if abs(digitProd(a) - digitSum(a)) == 0:
			count = count + 1
	print(n+1, count)