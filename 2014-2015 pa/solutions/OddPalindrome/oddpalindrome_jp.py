import sys

if __name__ == "__main__":
    s = sys.stdin.readline().strip()
    n = len(s)
    even_substrs = [s[i:j] for i in range(n) for j in range(i+2, n+1, 2)]
    isodd = all([x!=x[::-1] for x in even_substrs])
    if isodd: print("Odd.")
    else: print("Or not.")
