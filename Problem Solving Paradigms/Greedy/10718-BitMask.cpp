#include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned long int N,L,U;
	int i,ind;
	bool flag,flag2;
	while(cin>>N>>L>>U){
		flag = false;
		flag2 = true;
		bitset<32> n(N);
		//cout<<n<<endl;
		bitset<32> l(L);
		bitset<32> u(U);
		//cout<<u<<endl;
		bitset<32> ans(0);
		for(i = 31; i >= 0; i--){
			if(u[i] == 1){ind = i; break;}
		}
		for(i = ind; i >= 0; i--){
			if(l[i] && flag2){ans[i] = 1; continue;}
			if(n[i]){
				if(u[i])flag = true;
				continue;
			}
			ans[i] = 1;
			if(ans.to_ulong() > U)ans[i] = 0;
			if(ans[i] && flag2 && !l[i])flag2 = false;
		}
		cout<<ans.to_ulong()<<endl;
	}
	return 0;
}