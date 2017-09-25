#include <bits/stdc++.h>
using namespace std;

int main(){
	int test,i,j,k,l,a[250][250],n;
	int maxum,x;
	cin>>test;
	while(test--){
		cin>>n;
		maxum = -1000000000;
		for(i = 0; i < 2*n; i++){
			for(j = 0; j < 2*n; j++){
				if(i < n && j < n){
					cin>>a[i][j];
					a[i+n][j+n] = a[i+n][j] = a[i][j+n] = a[i][j];
				}
				if(i > 0) a[i][j] += a[i-1][j];
				if(j > 0) a[i][j] += a[i][j-1];
				if(i > 0 && j > 0) a[i][j] -= a[i-1][j-1];
			}
		}
		for(i = 0; i < n; i++)for(j = 0; j < n; j++){
			for(k = i; k < i + n; k++)for(l = j; l < j + n; l++){
				x = a[k][l];
				if(i > 0) x -= a[i-1][l];
				if(j > 0) x -= a[k][j-1];
				if(i > 0 && j > 0) x += a[i-1][j-1];
				if(x > maxum) maxum = x;
			}
		}
		cout<<maxum<<endl;
	}
	return 0;
}