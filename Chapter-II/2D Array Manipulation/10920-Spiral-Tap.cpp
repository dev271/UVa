#include <iostream>
#include <cstdio>
#include <utility>

using namespace std;
pair <long long int,long long int> work(long long int n,long long int i,long long int j,long long int x,long long int k){
	pair <long long int,long long int> p;
	if(x==n){
		p.first=i;
		p.second=j;
		return p;
	}
	i++;
	if(n<=x+k+1){
		p.first=i;
		p.second=j-(n-x-1);
		return p;
	}
	else if(n<=x+k+1+k+1){
		p.first=i-(n-(x+k+1));
		p.second=j-k;
		return p;
	}
	else if(n<=x+k+1+k+1+k+1){
		p.first=i-k-1;
		p.second=j-(k-(n-(x+k+1+k+1)));
		return p;
	}
	else if(n<=x+k+1+k+1+k+1+k+1){
		p.first=i-(k-(n-(x+k+1+k+1+k+1)))-1;
		p.second=j+1;
		return p;
	}
}
int main(){
	long long int N,n,k=1,x,i,j,mid;
	pair <long long int,long long int> p;
	scanf("%lld",&N);
	scanf("%lld",&n);
	while(N){
		k=1;
		mid=(N+1)/2;
		while(k*k<=n)
			k=k+2;
		k=k-2;
		x=k*k;
		i=mid+(k-1)/2;
		j=i;
		p=work(n,i,j,x,k);
		printf("Line = %lld, column = %lld.\n",p.first,p.second);
		scanf("%lld",&N);
	    scanf("%lld",&n);
	}
	return 0;
}