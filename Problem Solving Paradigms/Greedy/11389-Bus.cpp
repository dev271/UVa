#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long long int i,j,x,n,d,r,a[110],b[110];
	scanf("%lld %lld %lld",&n,&d,&r);
	while(n && d && r){
		for(i = 0; i < n; i++){
			scanf("%lld",&a[i]);
		}
		for(i = 0; i < n; i++){
			scanf("%lld",&b[i]);
		}
		x = 0;
		sort(a,a+n);
		sort(b,b+n);
		for(i = 0; i < n; i++){
			if(a[i] + b[n-i-1] > d) x += (a[i] + b[n-i-1] - d)*r; 
		}
		scanf("%lld %lld %lld",&n,&d,&r);
		printf("%lld\n",x);
	}
	return 0;
}
