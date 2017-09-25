#include <iostream>
#include <cmath>
using namespace std;

int flag[3010];
int main(){
	int n,i,flag1,x;
	int prev,next;
	while(cin>>n){
		for(i=0;i<3010;i++)
			flag[i]=0;
		cin>>prev;
		flag1=1;
		for(i=0;i<n-1;i++){
			cin>>next;
			x=abs(next-prev);
			flag[x]=1;
			prev=next;
		}
		for(i=1;i<n;i++){
			if(!flag[i]){
				flag1=0;
				break;
			}
		}
		if(flag1)
			cout<<"Jolly"<<endl;
		else
			cout<<"Not jolly"<<endl;
	}
	return 0;
}
