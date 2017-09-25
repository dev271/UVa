#include <bits/stdc++.h>

using namespace std;

int main(){
	int i,j,test,n,count;
	string s;
	scanf("%d",&test);
	j = 0;
	while(test--){
		j++;
		scanf("%d",&n);
		count = 0 ;
		cin>>s;
		for(i = 0; i < n; i++){
			if(s[i] == '.'){count++;i = i+2;}

		}
		printf("Case %d: %d\n",j,count);
	}
	return 0;
}