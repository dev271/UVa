#include <iostream>
using namespace std;
int min1;
void func(int a[][10],int n,int x,int b[],int flag[]){
	int sum=0,i,j=0;
	if(x==n){
		//for(i=0;i<n;i++)cout<<b[i]<<" ";
		//cout<<endl;
		for(i=0;i<n;i++){
			sum += a[j][b[i]];
			j++;
		}
		if(sum<min1)
			min1=sum;
		return;
	}
	for(i=0;i<n;i++){
		if(!flag[i]){
			flag[i]=1;
			b[x]=i;
			func(a,n,x+1,b,flag);
			flag[i]=0;
		}
	}
}
int main(){
	int i,j,t,n,a[10][10],flag[10],b[10];
	cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<10;i++)flag[i]=0;
		min1=100000000;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		func(a,n,0,b,flag);
		cout<<min1<<endl;
	}
}