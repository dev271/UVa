#include <iostream>
using namespace std;

bool sub(int a[],int n,int val){
	int sum;
	for(int i=0;i<(1<<n);i++){
		sum=0;
		for(int j=0;j<n;j++){
			if(i & (1<<j))
				sum += a[j];
		}
		if(sum==val){
			return 1;
		}
	}
	return 0;
}
int main(){
	int t,val,a[100],p;
	cin>>t;
	while(t--){
		cin>>val;
		cin>>p;
		for(int i=0;i<p;i++){
			cin>>a[i];
		}
		if(sub(a,p,val))
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}