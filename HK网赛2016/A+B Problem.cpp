#include <iostream>
#include <cmath>  
#include <cstring>  
#include <algorithm>   
using namespace std;  

const int N = 2e5+10;  
const double pi = acos(-1.0);  
  
char s1[N],s2[N];  
int len,res[N];  
  
struct Complex{  
	double r,i;  
	Complex(double r=0,double i=0):r(r),i(i) {
		
	};  
	Complex operator+(const Complex &rhs){  
		return Complex(r + rhs.r,i + rhs.i);  
	}  
	Complex operator-(const Complex &rhs){  
		return Complex(r - rhs.r,i - rhs.i);  
	}  
	Complex operator*(const Complex &rhs){  
		return Complex(r*rhs.r - i*rhs.i,i*rhs.r + r*rhs.i);  
	}  
} va[N],vb[N];  
  
//雷德算法--倒位序    
void rader(Complex F[],int len){ //len = 2^M,reverse F[i] with  F[j] j为i二进制反转   
	int j = len >> 1;  
	for(int i = 1;i < len - 1;++i){  
		if(i < j) swap(F[i],F[j]);  // reverse  
		int k = len>>1;  
		while(j>=k){  
			j -= k;  
			k >>= 1;  
		}  
		if(j < k) j += k;  
	}  
}  
//FFT实现  
void FFT(Complex F[],int len,int t){  
	rader(F,len);  
	for(int h=2;h<=len;h<<=1){ //分治后计算长度为h的DFT   
		Complex wn(cos(-t*2*pi/h),sin(-t*2*pi/h)); //单位复根e^(2*PI/m)用欧拉公式展开  
		for(int j=0;j<len;j+=h){  
			Complex E(1,0); //旋转因子  
			for(int k=j;k<j+h/2;++k){  
				Complex u = F[k];  
				Complex v = E*F[k+h/2];  
				F[k] = u+v; //蝴蝶合并操作  
				F[k+h/2] = u-v;  
				E=E*wn; //更新旋转因子  
			}  
		}  
	}  
	if(t==-1){   //IDFT  
		for(int i=0;i<len;++i){
			F[i].r/=len;  
		}
	}
}  
//数组开小会RE   
long long a[4*N];    
Complex F[4*N];    
long long num[4*N],sum[4*N];    
int n;  
long long zero;  
  
//求卷积   
void Conv(Complex F[],int len){  
	FFT(F,len,1);  
	for(long long i=0;i<len;++i) F[i] = F[i]*F[i];  
	FFT(F,len,-1);  
}  
  
void init(){    
	memset(num,0,sizeof(num));    
	cin >> n;  
	zero=0;   
	for(int i=0; i<n; i++){    
		cin >> a[i];  
		if(a[i]==0)zero++;  
		num[a[i]+50000]++;    
	}      
	sort(a, a + n);    
	int len1 = a[n-1] + 50000 + 1;    
	len = 1;    
	while(len < len1*2){
		len <<= 1;  
	}
	for(int i=0; i<len1; i++){    
		F[i] = Complex(num[i],0);    
	}
	for(int i=len1; i<len; i++){   
		F[i] = Complex(0,0);    
	}	
}    
	
void gao(){    
	Conv(F,len);  
	//num数组就是卷积后的结果，表示两两组合    
	for(int i=0; i<len; i++){    
		num[i] = (long long)(F[i].r+0.5);    
	}	  
	len = a[n-1]*2;    	  
	//本身和本身组合是不行的,减掉取两个相同的组合  
	for(int i=0; i<n; i++)    
		num[a[i]+a[i]+2*50000]--;   
	long long cnt = 0;    
	for(int i=0; i<n; i++){    
	   if(a[i]!=0){  
		 cnt+=num[a[i]+2*50000];  
		 cnt-=zero*2;  
	   }else{  
			cnt+=num[a[i]+2*50000];  
			cnt-=(zero-1)*2;  
	   }  
	}    
	cout << cnt << endl;  
}    
  
int main(){  
	int t;    
	init();  
	gao();  
	return 0;  
}  