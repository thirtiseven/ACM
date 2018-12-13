#include <iostream>
#include <set>
#include <algorithm>

using ll = long long;
const int maxn = 1e5+7;

ll mod, c, n;
ll color[maxn];

struct node {
	ll l, r;
	mutable ll v;
	node(ll L, ll R=-1, ll V = 0) : l(L), r(R), v(V) {}
	bool operator < (const node& o) const {
		return l < o.l;
	}
};

std::set<node> s;

//分割SET 返回一个pos位置的迭代器
std::set<node>::iterator split(int pos) {
	auto it = s.lower_bound(node(pos));
	if (it != s.end() && it->l == pos) return it;
	--it;
	if (pos > it->r) return s.end();
	ll L = it->l, R = it->r;
	ll V = it->v;
	s.erase(it);
	s.insert(node(L, pos - 1, V));
	return s.insert(node(pos, R, V)).first;
}

//区间赋值
ll ss, l, r;

void assign(ll p, ll x, ll a, ll b) {
	ss = color[p];
	l = (a+ss*ss)%mod;
	r = (a+(ss+b)*(ss+b))%mod;
	l++, r++;
	if (l > r) {
		std::swap(l, r);
	}
//	std::cout << l << " " << r << '\n';
	split(l);
	auto itr = split(int(r+1)), itl = split(int(l));
	for (; itl != itr; ++itl) {
		color[itl->v] -= (itl->r - itl->l + 1);
	}
	itl = split(int(l));
	s.erase(itl, itr);
	s.insert(node(l, r, x));
	color[x] += (r-l+1LL);
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> mod >> c >> n;
	std::fill(color, color+maxn, 0);
	s.insert(node(1, mod, 1));
	color[1] = mod;
	ll p, x, a, b;
	for (ll i = 0; i < n; i++) {
		std::cin >> p >> x >> a >> b;
		assign(p, x, a, b);
	}
	ll ans = 0;
	for (ll i = 1; i <= c; i++) {
		ans = std::max(ans, color[i]);
	}
	std::cout << ans << '\n';
}