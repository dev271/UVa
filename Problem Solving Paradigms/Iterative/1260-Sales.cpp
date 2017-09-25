#include <iostream>
using namespace std;

int main(){
	int a[1010];
	int test,n,i,j;
	long long int sum,count;
	cin>>test;
	while(test--){
		cin>>n;sum=0;
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		for(i=n-1;i>0;i--){
			count=0;
			for(j=i-1;j>=0;j--){
				if(a[i]>=a[j])
					count++;
			}
			sum = sum + count;
		}
		cout<<sum<<endl;
	}
}