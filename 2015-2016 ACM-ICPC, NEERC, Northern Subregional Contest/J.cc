#include <iostream>

const int maxn = 50000+7;
long long n, t;
long long pr[maxn], d[maxn];
long long fmin[maxn], q[maxn], num[maxn], a[maxn];

bool check(int k) {
	int head = 1, tail = 0;
	q[1] = 0;
	for (int i = 1; i < n; i++) {
		a[i] = q[head] + d[i];
		while (num[head] < i-k+1 && head <= tail) head++;
		while (a[i] <= q[tail] && head <= tail) tail--;
		num[++tail] = i;
		q[tail] = a[i];
		fmin[i] = q[head];
	}
	return q[head] <= t;
}

int main(int argc, char *argv[]) {  
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	std::cin >> n >> t;
	t -= (n-1);
	for (int i = 1; i < n; i++) {
		std::cin >> pr[i];
	}
	for (int i = 2; i < n; i++) {
		std::cin >> d[i];
	}
	d[1] = d[n] = 0; 
	for (int i = n-2; i > 0; i--) {
		if (pr[i] > pr[i+1]) pr[i] = pr[i+1];
	}
	int l = 1, r = n-1, mid;
	while (l <= r) {
		mid = (l+r)/2;
		if (check(mid)) {
			r = mid-1;
		} else {
			l = mid+1;
		}
	}
	std::cout << pr[l] << '\n';
}