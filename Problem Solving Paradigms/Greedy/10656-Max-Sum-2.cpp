#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	bool flag;
	int x;
	cin>>n;
	while(n){
		flag = false;
		for(int i = 0; i < n; i++){
			cin>>x;
			if(x != 0){
				if(flag)cout<<" ";
				cout<<x;
				flag = true;
			}
		}
		if(!flag)cout<<"0";
		cout<<endl;
		cin>>n;
	}
	return 0;
}