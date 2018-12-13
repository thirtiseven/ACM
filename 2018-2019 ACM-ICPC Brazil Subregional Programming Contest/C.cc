#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn = 100005;
struct node {
	ll x, y;
	node() {}
	node(ll x, ll y) :x(x), y(y) {}
	bool operator < (const node nod) const {
		return x < nod.x;
	}
}no1[maxn], no2[maxn];
ll X, Y, n, m, x, y;
ll tree1[maxn], tree2[maxn];
void add1(int i, ll x) {
	for (; i <= n; i += i & -i)
		tree1[i] += x;
}
ll sum1(int i) {
	ll ret = 0;
	for (; i; i -= i & -i) ret += tree1[i];
	return ret;
}
void add2(int i, ll x) {
	for (; i <= n; i += i & -i)
		tree2[i] += x;
}
ll sum2(int i) {
	ll ret = 0;
	for (; i; i -= i & -i) ret += tree2[i];
	return ret;
}
int cmp(node no1, node no2) { return no1.y < no2.y; }
int main()
{
	scanf("%lld%lld%lld%lld", &X, &Y, &n, &m);
	ll ans = n * m + n + m + 1ll;
	for (int i = 1; i <= n; i++)
		scanf("%lld%lld", &no1[i].x, &no1[i].y);
	for (int i = 1; i <= m; i++)
		scanf("%lld%lld", &no2[i].x, &no2[i].y);
	sort(no1 + 1, no1 + n + 1, cmp);
	for (int i = 1; i <= n; i++) no1[i].y = i;
	sort(no2 + 1, no2 + m + 1, cmp);
	for (int i = 1; i <= m; i++) no2[i].y = i;
	sort(no1 + 1, no1 + n + 1);
	sort(no2 + 1, no2 + m + 1);
	for (int i = 1; i <= n; i++) {
		ans += sum1(n) - sum1(no1[i].y);
		add1(no1[i].y, 1);
	}
	for (int i = 1; i <= m; i++) {
		ans += sum2(m) - sum2(no2[i].y);
		add2(no2[i].y, 1);
	}
	printf("%lld\n", ans);
	return 0;
}