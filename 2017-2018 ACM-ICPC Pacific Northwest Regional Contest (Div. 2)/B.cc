#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
char arr[40][40];
int flag[256];

bool justok(){
	//对列的判定 
	for(int i = 0; i < n; i++){
		for(int v = 0; v < 256; v++){
			flag[v] = 0;
		}
		for(int j = 0; j < n ; j++){
			if(flag[int(arr[i][j])] == 1){
				return false;
			}
			else{
				flag[int(arr[i][j])] = 1;
			}
		}
	}
	for(int v = 0; v < 256; v++){
		flag[v] = 0;
	}
	//对行的判定 
	for(int i = 0; i < n; i++){
		for(int v = 0; v < 256; v++){
			flag[v] = 0;
		}
		for(int j = 0; j < n ; j++){
			if(flag[int(arr[j][i])] == 1){
				return false;
			}
			else{
				flag[int(arr[j][i])] = 1;
			}
		}
	}
	return true;
}

bool ok(){
	if(n >= 10){
		for(int i = 0; i < 10; i++){
			if(int(arr[0][i] - '0') != i){
				return false;
			}
			if(int(arr[i][0] - '0') != i){
				return false;
			}
		}
		for(int i = 10; i < n; i++){
			if(int(arr[0][i] - 'A') + 10 != i){
				return false;
			}
			if(int(arr[i][0] - 'A') + 10 != i){
				return false;
			}
		}
	}
	else{
		for(int i = 0; i < n; i++){
			if(int(arr[0][i] - '0') != i){
				return false;
			}
			if(int(arr[i][0] - '0') != i){
				return false;
			}
		}	
	}
	return true;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	if(justok() == true){
		if(ok() == true){
			cout << "Reduced";
		}
		else{
			cout << "Not Reduced";
		}
	}
	else{
		cout << "No";
	}
	return 0;
}