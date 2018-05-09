#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long LL;

const int MAXN = 200010, MAXT = 1000010;

const LL INF = 1LL << 60;

int len[MAXN], ptr[MAXN], base[MAXN], which[MAXT], type[MAXT], f[MAXT], t[MAXT];
LL A[MAXN], B[MAXN], C[MAXN];
bool reached[MAXN];

inline void addLine(int idx, LL a, LL b) {
    int l;
    while ((l = len[idx]) >= 2 + base[idx-1] && (B[l-2] - B[l-1]) * (a - A[l-1]) >= (B[l-1] - b) * (A[l-1] - A[l-2])) {
        --len[idx];
    }
    A[l] = a; B[l] = b;
    ptr[idx] = min(ptr[idx], len[idx]++);
}

inline LL minValue(int idx, LL x) {
    if (len[idx] == 0) return INF;
    int p;
    while ((p = ptr[idx]) + 1 < len[idx] && A[p+1] * x + B[p+1] <= A[p] * x + B[p]) {
        ++ptr[idx];
    }
    return A[p] * x + B[p];
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    base[1]++;
    for (int i = 1, a, b, s, e; i <= m; i++) {
        scanf("%d%d%d%d", &a, &b, &s, &e);
        which[s] = which[e] = i;
        f[s] = a; t[e] = b;
        type[s] = +1; type[e] = -1;
        base[b]++;
        C[i] = INF;
    }

    for (int i = 1; i <= n; i++) {
        base[i] += (len[i] = ptr[i] = base[i-1]);
    }
    addLine(1, 0, 0);

    reached[1] = true;
    LL ans = INF;
    for (int i = 0; i < MAXT; i++) {
        if (!which[i]) continue;
        if (type[i] == +1) {
            if (reached[f[i]]) {
                C[which[i]] = i * (LL) i + minValue(f[i], i);
            }
        } else {
            if (C[which[i]] < INF) {
                if (t[i] == n) ans = min(ans, C[which[i]]);
                addLine(t[i], -2 * i, C[which[i]] + i * (LL) i);
                reached[t[i]] = true;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}