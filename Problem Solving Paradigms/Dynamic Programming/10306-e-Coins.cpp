#include <bits/stdc++.h>
using namespace std;

int s,memo[1000][1000];
pair<int, int> p[100];
int n;
int change(int x, int y){
	int i,min1 = 1000000000;
	float z = sqrt(float(x*x + y*y));
	if(z == s)return 0;
	if(z > s)return 1000000;
	if(memo[x][y] != -1)return memo[x][y];
	for(i = 0; i < n; i++){
		if(min1 > change(x + p[i].first, y + p[i].second))
			min1 = change(x + p[i].first, y + p[i].second);
	}
	return memo[x][y] = 1 + min1;
}	

int main(){
	int i,test;
	cin>>test;
	while(test--){
		cin>>n>>s;
		memset(memo, -1, sizeof(memo));
		for(i = 0; i < n; i++){
			cin>>p[i].first>>p[i].second;
		}
		if(change(0,0) >= 1000000) cout<<"not possible"<<endl;
		else cout<<change(0,0)<<endl;
	}
	return 0;
}