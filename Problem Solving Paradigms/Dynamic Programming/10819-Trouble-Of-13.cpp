#include <bits/stdc++.h>
using namespace std;

int c[110],v[110],b,n,memo[110][11000];
bool flag;
int val(int id,int B){
	if(B > b && b < 1800) return -1000;
	if(B > b + 200) return -1000;
	if(id == n){
		if(B > b && B <= 2000) return -1000;
		return 0;
	} 
	if(memo[id][B] != -1) return memo[id][B];
	return memo[id][B] = max(val(id + 1, B), v[id] + val(id + 1, B + c[id]));
}

int main(){
	while(cin>>b>>n){
		memset(memo, -1, sizeof(memo));
		for(int i = 0; i < n; i++){
			cin>>c[i]>>v[i];
		}
		cout<<val(0,0)<<endl;

	}
	return 0;
}