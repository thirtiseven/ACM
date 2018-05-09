import sys

if __name__ == "__main__":
    s = sys.stdin.readline().strip()
    n = len(s)
    p = 0
    i1, i2 = -1, -1
    minv, maxv = 0, 0
    for i, c in enumerate(s):
        p += 1 if c == 'B' else -1
        if p < minv:
            i1, minv = i, p
        if p > maxv:
            i2, maxv = i, p
    if i1 > i2:
        print("%d %d" % (i2+2, i1+1))
    else:
        print("%d %d" % (i1+2, i2+1))
