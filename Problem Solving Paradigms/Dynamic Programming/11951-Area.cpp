#include <bits/stdc++.h>
using namespace std;

int main(){
	int i,j,k,l,n,m,test,area,t,ar;
	long long int a[110][110],x,minsum,p,kys;
	cin>>test;
	t = 1;
	while(test--){
		cin>>n>>m>>kys;
		minsum = 1000000002;
		area = 0;
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				cin>>a[i][j];
				if(i > 0) a[i][j] += a[i-1][j];
				if(j > 0) a[i][j] += a[i][j-1];
				if(i > 0 && j > 0) a[i][j] -= a[i-1][j-1];
			}
		}
		for(i = 0; i < n; i++)for(j = 0; j < m; j++){
			for(k = i; k < n; k++)for(l = j; l < m; l++){
				x = a[k][l];
				if(i > 0) x -= a[i-1][l];
				if(j > 0) x -= a[k][j-1];
				if(i > 0 && j > 0) x += a[i-1][j-1];
				ar = (k-i+1)*(l-j+1);
				if((x <= minsum && ar >= area && x <= kys) || (ar > area && x <= kys)){
					area = ar;
					minsum = x;
				} 
			}
		}
		if(area == 0)cout<<"Case #"<<t++<<": "<<area<<" "<<0<<endl;

		else cout<<"Case #"<<t++<<": "<<area<<" "<<minsum<<endl;
	}
}