import sys

if __name__ == "__main__":
    a, b = map(int, sys.stdin.readline().split())
    m = 10**6
    sieve = [False for _ in range(m + 1)]
    remaining_factor = [i for i in range(a, b+1)]
    factor_products = [1 for _ in range(a, b+1)]
    for p in range(2, m + 1):
        if sieve[p]:
            continue
        for i in range(p*2, m+1, p):
            sieve[i] = True
        offset = (-a) % p
        for i in range(offset, b-a+1, p):
            cnt = 0
            while remaining_factor[i] % p == 0:
                remaining_factor[i] /= p
                cnt += 1
            factor_products[i] *= (p**(cnt+1)-1)/(p-1)
    ans = 0
    for prod, remaining in zip(factor_products, remaining_factor):
        if remaining > 1:
            ans += prod*(1+remaining)
        else:
            ans += prod
    print(ans)
