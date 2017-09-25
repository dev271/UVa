#include <bits/stdc++.h>
using namespace std;

int n,m,c[1010];

bool can(int x){	
	int total = 0, curr = 0;
	for(int i = 0; i < n; i++){
		if(c[i] > x) return false;
		if(curr + c[i] > x) curr = 0 ;
		if(curr == 0) total++ ;
		curr += c[i];
		if(total > m) return false;
	}
	return true;
}

int main(){
	int mid, high, low;
	while(scanf("%d %d",&n,&m) == 2){
		for(int i = 0; i < n; i++){
			scanf("%d",&c[i]);
		}
		high = 1000000*n, low = 0;
		while(low<high){
			//printf("%d %d\n",low,high);
			mid = (low+high)/2;
			if(can(mid))high = mid ; 
			else low = mid + 1;
		}
		printf("%d\n",low);
	}
	return 0;
}