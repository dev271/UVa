#include <iostream>
#include <cmath>
using namespace std;

int main(){
	long long int i,j,k,test,n,m,x,close[30],sum,a[1010],b[30],t;
	t=1;
	cin>>n;
	while(n){
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		cin>>m;
		for(i=0;i<m;i++){
			cin>>b[i];
			close[i]=10000000000000;
		}
		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				sum=a[i]+a[j];
				for(k=0;k<m;k++){
					if(abs(sum-b[k])<abs(close[k]-b[k]))
						close[k]=sum;
				}
			}
		}
		printf("Case %lld:\n",t);
		for(i=0;i<m;i++){
			printf("Closest sum to %lld is %lld.\n",b[i],close[i]);
		}
		t++;
		cin>>n;
	}
}