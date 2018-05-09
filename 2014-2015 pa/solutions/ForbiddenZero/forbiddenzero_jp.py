import sys

if __name__ == "__main__":
    n = int(sys.stdin.readline()) + 1
    while '0' in str(n): n += 1
    print(n)
