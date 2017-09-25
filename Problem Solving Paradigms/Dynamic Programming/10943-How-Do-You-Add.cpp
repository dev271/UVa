#include <bits/stdc++.h>
using namespace std;

int n,k,memo[110][110];
int num(int n, int k){
	int ans = 0;
	if(k == 1)return 1;
	if(memo[n][k] != -1)return memo[n][k];
	for(int i = 0; i <= n; i++){
		ans += num(n - i, k - 1) % 1000000;
		ans = ans % 1000000;
	}
	return memo[n][k] = ans;
}
int main(){
	cin>>n>>k;
	while(n && k){
		memset(memo, -1, sizeof(memo));
		cout<<num(n,k)<<endl;
		cin>>n>>k;
	}
	return 0;
}