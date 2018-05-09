import sys

def appealing(x, y, S):
    return x >= 2 and y >= 1 and S >= x+y and S % (x+y) in [0, x]

if __name__ == "__main__":
    S = int(sys.stdin.readline())
    appealing_list = [(x, x) for x in range(S+1) if appealing(x, x, S)] \
        + [(x, x-1) for x in range(S+1) if appealing(x, x-1, S)]
    print("%d:" % S)
    for pattern in sorted(appealing_list):
        print("%d,%d" % pattern)
