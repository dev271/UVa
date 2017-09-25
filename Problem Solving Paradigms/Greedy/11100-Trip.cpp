#include <bits/stdc++.h>
using namespace std;

int main(){
	bool flag[10010];
	int a[10010][2],b[10010];
	int n,i,j,count,temp;
	cin >> n;
	while(n){
		count = 0;
		for(i = 0; i < 10010; i++)flag[i] = false;
		for(i = 0; i < 10010; i++)a[i][1] = -1;
		for(i = 0; i < n; i++) cin>>b[i];
		sort(b,b+n);
		for(i = 0; i < n; i++) a[i][0] = b[i];
		for(i = 0; i < n; i++){
			if(!flag[i])count++;
			for(j = i+1; j < n; j++){	
				if(a[j][0] > a[i][0] && !flag[j]){
					flag[j] = true;
					a[i][1] = j;
					break;
				}
			}
		}
		cout<<count<<endl;
		for(i = 0; i < count; i++){
			for(j = 0; j+i < n; j = j + count){
				if(j!=0)cout<<" ";
				cout<<a[j+i][0];
			}			
			cout<<endl;
		}
		cin>>n;
		if(n!=0)cout<<endl;
	}
	return 0;
}