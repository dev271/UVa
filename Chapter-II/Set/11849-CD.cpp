#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int min1;
void sub(int a[],int n,int val){
	int sum,j,i,k;
	for(i=0;i<1<<n;i++){
		sum=0;
		for(j=0;j<n;j++){
			if(i & (1<<j))
				sum += a[j];
		}
		if(val>=sum && val-sum<min1){
			min1=val-sum;
			v.clear();
			for(k=0;k<n;k++){
				if(i & (1<<k))
					v.push_back(a[k]);
		}
		}
	}
	return ;
}
int main(){
	int t,val,a[100],p;
	while(cin>>val){
		cin>>t;
		v.clear();
		min1=100000000;
		for(int i=0;i<t;i++){
			cin>>a[i];
		}
		sub(a,t,val);
		for(int j=0;j<v.size();j++){
			cout<<v[j]<<" ";
		}
		cout<<"sum:"<<val-min1<<endl;
	}
	return 0;
}