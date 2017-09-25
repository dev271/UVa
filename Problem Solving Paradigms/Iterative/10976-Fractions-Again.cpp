#include <iostream>
#include <cstdio>
using namespace std;

long long int a[20010];
int main(){
	long long int k,y,i;
	int count;
	double x;
	while(cin>>k){
		count=0;
		for(i=k+1;i<=2*k;i++){
			x=((double)k)*i/(i-k);
			if(x-(int)x==0){
				a[i]=x;
				count++;
			}
			else
				a[i]=0;
		}
		cout<<count<<endl;
		for(i=k+1;i<=2*k;i++){
			if(a[i]){
				printf("1/%d = 1/%d + 1/%d\n",k,a[i],i);
			}
		}
	}
	return 0;
}