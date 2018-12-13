#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

struct node {
	int l, r;
	mutable int v;
	node(int L, int R = -1, int V = 0) : l(L), r(R), v(V) {}
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
	int L = it->l, R = it->r;
	int V = it->v;
	s.erase(it);
	s.insert(node(L, pos - 1, V));
	return s.insert(node(pos, R, V)).first;
}

//区间加值
void add(int l, int r, int val=1) {
	split(l);
	auto itr = split(r+1), itl = split(l);
	for (; itl != itr; ++itl) itl->v += val;
}

//区间赋值
void assign(int l, int r, int val = 0) {
	split(l);
	auto itr = split(r+1), itl = split(l);
	s.erase(itl, itr);
	s.insert(node(l, r, val));
}

int main(int argc, char *argv[]) {  
	int q, t, d, i;
	char op;
	std::cin >> q;
	while (q--) {
		std::cin >> op;
		if (op == '+') {
			
		} else if (op == '-') {
			
		} else {
			
		}
	}
}