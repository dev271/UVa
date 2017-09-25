#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,k,i,a[100010],max,curr_max,n=1;
	bool flag;
	scanf("%d",&t);
	while(t--){
		flag = false;
		max = -1;
		scanf("%d",&k);
		for(i = 0; i<k; i++){
			scanf("%d",&a[i]);
		}
		max = a[0];
		curr_max = max-1;
		for(i = 0; i<k-1; i++){
			if(a[i+1] - a[i] > max){
				max = a[i+1] - a[i];
				curr_max = max-1;
				flag = false;
			}
			else if(a[i+1] - a[i] == max || a[i+1] - a[i] > curr_max) flag = true;
			else if(a[i+1] - a[i] == curr_max) curr_max--;
		}
		if(flag) printf("Case %d: %d\n",n,max+1);
		else printf("Case %d: %d\n",n,max);
		n++;
	}
	return 0;
}