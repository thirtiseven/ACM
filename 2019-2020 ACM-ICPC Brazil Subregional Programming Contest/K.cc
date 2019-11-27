#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

namespace linear_seq {
	const int N = 10010;
	typedef long long ll;
	constexpr ll mod = (ll) 1e9 + 7;

	ll pow_mod(ll a, ll b) {
		ll r = 1;
		for (a %= mod; b; b >>= 1, a = a * a % mod) {
			if (b & 1)r = r * a % mod;
		}
		return r;
	}

	ll res[N], base[N], _c[N], _md[N];
	vector<int> Md;

	void mul(ll *a, ll *b, int k) {
		k <<= 1;
		for (int i = 0; i < k; ++i) _c[i] = 0;
		k >>= 1;
		for (int i = 0; i < k; ++i) {
			if (a[i]) {
				for (int j = 0; j < k; ++j) {
					_c[i + j] = (_c[i + j] + a[i] * b[j]) % mod;
				}
			}
		}
		for (int i = k + k - 1; i >= k; i--) {
			if (_c[i]) {
				for (const int md: Md) {
					_c[i - k + md] = (_c[i - k + md] - _c[i] * _md[md]) % mod;
				}
			}
		}
		for (int i = 0; i < k; ++i) {
			a[i] = _c[i];
		}
	}

	int solve(ll n, vector<int> a, vector<int> b) { // a 系数 b 初值 b[n+1]=a[0]*b[n]+...
//        printf("SIZE %d\n",SZ(b));
//		for (auto it: b) {
//			std::cout << it << ' ';
//		}
		ll ans = 0, pnt = 0;
		int k = (int) a.size();
		assert(a.size() == b.size());
		for (int i = 0; i < k; ++i) {
			_md[k - 1 - i] = -a[i];
		}
		_md[k] = 1;
		Md.clear();
		for (int i = 0; i < k; ++i) {
			if (_md[i] != 0) {
				Md.push_back(i);
			}
		}
		for (int i = 0; i < k; ++i) {
			res[i] = base[i] = 0;
		}
		res[0] = 1;
		while ((1ll << pnt) <= n) {
			pnt++;
		}
		for (int p = pnt; p >= 0; p--) {
			mul(res, res, k);
			if ((n >> p) & 1) {
				for (int i = k - 1; i >= 0; i--) {
					res[i + 1] = res[i];
				}
				res[0] = 0;
				for (const int md: Md) {
					res[md] = (res[md] - res[k] * _md[md]) % mod;
				}
			}
		}
		for (int i = 0; i < k; ++i) {
			ans = (ans + res[i] * b[i]) % mod;
		}
		if (ans < 0) ans += mod;
		return ans;
	}

	vector<int> BM(vector<int> s) {
		vector<int> C(1, 1), B(1, 1);
		int L = 0, m = 1, b = 1;
		for (int n = 0; n < (int) s.size(); ++n) {
			ll d = 0;
			for (int i = 0; i <= L; ++i) {
				d = (d + (ll) C[i] * s[n - i]) % mod;
			}
			if (d == 0) {
				++m;
			}
			else if (2 * L <= n) {
				vector<int> T = C;
				ll c = mod - d * pow_mod(b, mod - 2) % mod;
				while (C.size() < B.size() + m) {
					C.push_back(0);
				}
				for (int i = 0; i < (int) B.size(); ++i) {
					C[i + m] = (C[i + m] + c * B[i]) % mod;
				}
				L = n + 1 - L;
				B = T;
				b = d;
				m = 1;
			} else {
				ll c = mod - d * pow_mod(b, mod - 2) % mod;
				while (C.size() < B.size() + m) {
					C.push_back(0);
				}
				for (int i = 0; i < (int) B.size(); ++i) {
					C[i + m] = (C[i + m] + c * B[i]) % mod;
				}
				++m;
			}
		}
		return C;
	}

	int gao(vector<int> a, ll n) {
		vector<int> c = BM(a);
		c.erase(c.begin());
		for (int &x:c) {
			x = (mod - x) % mod;
		}
		return solve(n, c, vector<int>(a.begin(), a.begin() + c.size()));
	}
}

using namespace linear_seq;

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	if (n==1) {
		std::cout << "2\n";
		exit(0);
	}
	std::vector<int> p;
	p.push_back(4);
	p.push_back(24);
	p.push_back(96);
	p.push_back(416);
	p.push_back(1536);
	p.push_back(5504);
	p.push_back(18944);
	p.push_back(64000);
	p.push_back(212992);
	p.push_back(702464);
	p.push_back(2301952);
	p.push_back(7512064);
	p.push_back(24444928);
//	p.push_back(79396864);
//	p.push_back(257556480);
//	p.push_back(834797568);
//	p.push_back(2704277504);
//	p.push_back(8757182464);
//	p.push_back(28351397888);	
	std::cout << gao(p, n-1);
}