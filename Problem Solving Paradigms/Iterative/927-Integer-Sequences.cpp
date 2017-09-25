#include <iostream>
#include <cmath>
using namespace std;
long long int a[25];
int main(){
	long long int test,deg,d,k,i,y,ans,prod;
	double n,x;
	cin>>test;
	while(test--){
		cin>>deg;
		for(i=0;i<=deg;i++){
			cin>>a[i];
		}
		ans=a[0];
		cin>>d>>k;
		x=((double)k)/d;
		//cout<<x;
		n=-0.5+sqrt(1+8*x)/2;
		//cout<<n;
		if((n-(int)n)==0){
			y=(int)n;
		}
		else
			y=(int)n+1;
		prod=y;
		for(i=1;i<=deg;i++){
			ans=ans+prod*a[i];
			prod=prod*y;
		}
		cout<<ans<<endl;
	}
}
