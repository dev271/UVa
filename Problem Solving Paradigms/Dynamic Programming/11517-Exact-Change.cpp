#include <bits/stdc++.h>
using namespace std;

int s,c[110],d[110],n,dp1[110][11000],dp2[110][12000];
int val(int id, int rem){
	if(rem <= 0)return rem;
	if(id == n) return -100000000;
	if(dp1[id][rem] != -1) return dp1[id][rem];
	return dp1[id][rem] = max(val(id + 1, rem), val(id + 1, rem - c[id]));
}

int change(int id, int rem){
	if(rem == 0)return 0;
	if(id == n)return 100000000;
	if(dp2[id][rem]!=-1)return dp2[id][rem];
	if(c[id] > rem) return dp2[id][rem] = change(id + 1, rem);
	return dp2[id][rem] = min(change(id+1,rem),1+change(id+1,rem-c[id]));
}
int main(){
	int i,j,test,x;
	cin>>test;
	while(test--){
		cin>>s>>n;
		memset(dp1, -1, sizeof(dp1));
		memset(dp2, -1, sizeof(dp2));
		for(i = 0; i < n; i++){
			cin>>c[i];
		}
		/*if(t++ == 72){
			cout<<endl<<endl<<s<<" "<<n<<endl;
			for(i = 0; i < n; i++){
				cout<<c[i]<<endl;
			}
			cout<<endl<<endl;
			for(i = 0; i < n; i++){
				for(j = i+1; j < n; j++){
					if(c[i] + c[j] == 7662)cout<<1;
				}
			}
		}*/
		x = s - val(0,s);
		cout<<x<<" "<<change(0,x)<<endl;
	}
}