#include <iostream>
#include <cstring>
#define maxm 10 
typedef long long LL;

const LL Mod=2147493647;
struct Matrix { 
	int n, m;
	LL mat[maxm][maxm];
	void clear() {
		memset(mat, 0, sizeof(mat));
	}

	Matrix(int n, int m) :n(n), m(m) {
		//不要设置默认构造函数，让编译器检查初始化遗漏 
		clear();
	}	
	Matrix operator *(const Matrix &M) const { 
		if (m != M.n){
			std::cout << "Wrong!" << std::endl;
			return Matrix(-1, -1); 
		}	
		Matrix res(n, M.m); 
		res.clear();
		int i,j,k;
		for (i = 0; i < n; ++i)
			for (j = 0; j < M.m; ++j)
				for (k = 0; k < m; ++k) {
					res.mat[i][j] += mat[i][k] * M.mat[k][j]%Mod; 
					res.mat[i][j] %= Mod;
				} 
		return res;
	}	
	Matrix operator ^(LL b) const { // 矩阵快速幂 ， 取余Mod 
		if (n != m) 
			return Matrix(-1, -1);
		Matrix a(*this);
		Matrix res(n, n);
		res.clear();
		for (LL i = 0; i < n; ++i) 
			res.mat[i][i] = 1; 
		for (; b; b >>= 1) {
			if (b & 1) {
				res = a * res;
			}
			a = a * a; 
		}
		return res; 
	}

	LL* operator [](int i) { 
		return mat[i];
	}

	void Print() const {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) 
				std::cout << mat[i][j] << ' ';
			std::cout << '\n'; 
		}
	}
};

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	Matrix mm(7, 7);
	for(int i = 0; i < 7; i++) {
		mm[i][i] = 1;
	}
	for(int i = 0; i < 7; i++) {
		mm[i][6] = 1;
	}
	mm[0][2] = mm[1][0] = 1;
	mm[1][1] = 0;
	mm[1][6] = 0;
	mm[4][5] = 2;
	mm[3][4] = mm[3][5] = 3;
	mm[2][3] = mm [2][5] = mm[0][3] = mm [0][5] = 4;
	mm[2][4] = mm[0][4] = 6;
	mm[0][1] = 2;
	//mm.Print();
	while(T--) {
		Matrix t(7,1);
		LL nn;
		std::cin >> nn >> t[1][0] >> t[0][0];
		t[2][0] = 16;
		t[3][0] = 8;
		t[4][0] = 4;
		t[5][0] = 2;
		t[6][0] = 1;
		//t.Print();
		mm=mm^(nn-2);
		t = mm * t;
		std::cout << t[0][0]%Mod << '\n';
 	}
	return 0;
}