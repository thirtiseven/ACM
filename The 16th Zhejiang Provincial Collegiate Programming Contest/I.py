
ans = [[0,1,0],[1,0,1],[0,1,0]]

T = int(raw_input())
while T > 0:
	T = T-1
	a, b = map(int,raw_input().split(' '))
	print(ans[(a-1)%3][b%3])
		