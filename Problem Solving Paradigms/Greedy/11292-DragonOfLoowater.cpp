#include <bits/stdc++.h>

using namespace std;
int main(){
	long long int sum,i,j,n,m;
	long long int d[20010],k[20010];
	cin>>n>>m;
	bool flag;
	while(n && m){
		sum = 0;
		flag = true;
		for(i = 0; i < n; i++){
			cin>>d[i];
		}
		for(i = 0; i < m; i++){
			cin>>k[i];
		}	
		sort(d,d+n);
		sort(k,k+m);
		j = 0;
		for(i = 0; i < n; i++){
			while(d[i] > k[j] && j < m){
				j++;
			}
			if(j >= m){flag = false; break;}
			sum = sum + k[j];
			j++;
		}
		if(flag && i==n) cout<<sum<<endl;
		else cout<<"Loowater is doomed!"<<endl;
		cin>>n>>m;
	}
	return 0;
}