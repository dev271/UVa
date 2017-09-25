#include <iostream>
using namespace std;

bool isPrime(int a,int b[]){
	for(int i=0;i<11;i++){
		if(a==b[i])return true;
	}
	return false;
}
void BT(int n,int ind,int a[],int b[],int flag[]){
	int i,j;
	for(i=2;i<=n;i++){
		if(flag[i]){
				a[ind]=i;
				if(isPrime(a[ind]+a[ind-1],b)){
					if(ind==n-1 && isPrime(a[ind]+1,b)){	
						for(j=0;j<n;j++){
							if(j!=n-1)cout<<a[j]<<" ";
							else cout<<a[j];
						}
						cout<<endl;return;
					}
				else if(ind==n-1)return;
				flag[i]=0;
					BT(n,ind+1,a,b,flag);
				}
				flag[i]=1;
		}
	}
}
int main(){
	int b[11]={3,5,7,11,13,17,19,23,29,31,37};
	int a[17],flag[17];
	int n,i,k=0;
	while(cin>>n){
		if(k!=0)cout<<endl;
		cout<<"Case "<<++k<<":"<<endl;
		a[0]=1;
		for(i=0;i<17;i++)flag[i]=1;
		BT(n,1,a,b,flag);
	}
	return 0;
}