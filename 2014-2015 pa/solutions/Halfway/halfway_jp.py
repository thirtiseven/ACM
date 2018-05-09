import sys

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    T = n*(n-1)/2
    m = int((T+1)/2)
    k = int(n+0.5-(((2*n-1)**2-8*(m-1))**0.5)/2)
    while True:
        v = (k-k*k-2*n+2*k*n)/2+1
        if v > m:
            k -= 1
            break
        k += 1
    print(k)
