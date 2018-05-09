import sys

if __name__ == "__main__":
    p = list(map(float, sys.stdin.readline().split()))
    v = sum(p[i]*(i+1) for i in range(6))
    print("%.3f" % (abs(3.5-v) / max(p)))
