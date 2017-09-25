#include <bits/stdc++.h>
using namespace std;

int main(){
	int i,j,k,l,a[110][110],n;
	int maxum,x;
	while(cin>>n){
		maxum = -127*100*100;
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				cin>>a[i][j];
				if(i > 0) a[i][j] += a[i-1][j];
				if(j > 0) a[i][j] += a[i][j-1];
				if(i > 0 && j > 0) a[i][j] -= a[i-1][j-1];
			}
		}
		for(i = 0; i < n; i++)for(j = 0; j < n; j++){
			for(k = i; k < n; k++)for(l = j; l < n; l++){
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