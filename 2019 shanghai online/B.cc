#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using LL = int;

struct node {
	int l, r;
	mutable LL v;
	node(int L, int R = -1, LL V = 0) : l(L), r(R), v(V) {}
	bool operator < (const node& o) const {
		return l < o.l;
	}
};

struct input{
	int l, r, len;
	input(int L, int R, int LEN) : l(L), r(R), len(LEN) {}
};

std::set<node> s;
std::vector<input> v;

bool cmp(input a, input b) {
	return a.len > b.len;
}

//分割SET 返回一个pos位置的迭代器
std::set<node>::iterator split(int pos) {
	auto it = s.lower_bound(node(pos));
	if (it != s.end() && it->l == pos) return it;
	--it;
	if (pos > it->r) return s.end();
	int L = it->l, R = it->r;
	LL V = it->v;
	s.erase(it);
	s.insert(node(L, pos - 1, V));
	return s.insert(node(pos, R, V)).first;
}

//区间加值
void add(int l, int r) {
	split(l);
	auto itr = split(r+1), itl = split(l);
	for (; itl != itr; ++itl) itl->v = 1-itl->v;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		int n, m, l, r;
		std::cin >> n >> m;
		s.clear();
		v.clear();
		s.insert(node(1, n, 0));
		for (int i = 0; i < m; i++) {
			std::cin >> l >> r;
			v.push_back(input(l, r, r-l+1));
		}
		std::sort(v.begin(), v.end(), cmp);
		for (auto it: v) {
			add(it.l, it.r);
		}
		int ans = 0;
		for (auto it: s) {
			if (it.v == 1) {
				ans += (it.r-it.l+1);
			}
		}
		std::cout << "Case #" << CAS << ": " <<  ans << '\n';
	}
}