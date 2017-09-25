#include <bits/stdc++.h>
using namespace std;

int main(){
	int i,j,k,l,m,n;
	long long int temp,maxum,x,test,a[25][25][25],A,B,C;
	cin>>test;
	temp = test;
	while(test--){
		cin>>A>>B>>C;
		maxum = -2147483648;
		for(i = 0; i < A; i++){
			for(j = 0; j < B; j++){
				for(k = 0; k < C; k++){
					cin>>a[i][j][k];
					if(i>0)a[i][j][k] += a[i-1][j][k];
					if(j>0)a[i][j][k] += a[i][j-1][k];
					if(k>0)a[i][j][k] += a[i][j][k-1];
					if(i>0 && j>0)a[i][j][k] -= a[i-1][j-1][k];
					if(i>0 && k>0)a[i][j][k] -= a[i-1][j][k-1];
					if(j>0 && k>0)a[i][j][k] -= a[i][j-1][k-1];
					if(i>0 && j>0 && k>0)a[i][j][k] += a[i-1][j-1][k-1];
				}
			}
		}	
		for(i = 0; i < A; i++)for(j = 0; j < B; j++)for(k = 0; k < C; k++){
			for(l = i; l < A; l++)for(m = j; m < B; m++)for(n = k; n < C; n++){
				x = a[l][m][n];
				if(i>0)x -= a[i-1][m][n];
				if(j>0)x -= a[l][j-1][n];
				if(k>0)x -= a[l][m][k-1];
				if(i>0 && j>0)x += a[i-1][j-1][n];
				if(i>0 && k>0)x += a[i-1][m][k-1];
				if(j>0 && k>0)x += a[l][j-1][k-1];
				if(i>0 && j>0 && k>0)x -= a[i-1][j-1][k-1];
				if(x > maxum) maxum = x;
			}
		}
		if(test!=temp-1)cout<<endl;
		cout<<maxum<<endl;
	}
	return 0;
}