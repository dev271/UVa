#include <bits/stdc++.h>
using namespace std;

int main(){
	int ht[100000],bs[100000],LIS[100000],LDS[100000];
	int test,n,i,j,max1,max2,max3,max4,t;
	cin>>test;
	t = 1;
	while(test--){
		cin>>n;
		for(i = 0; i < n; i++){
			cin>>ht[i];
		}
		for(i = 0; i < n; i++){
			cin>>bs[i];
		}
		LIS[0] = LDS[0] = bs[0];
		max3 = max4 = bs[0];
		for(i = 1; i < n; i++){
			max1 = -1; max2 = -1;
			LIS[i] = bs[i];
			LDS[i] = bs[i];
			for(j = 0; j < i; j++){
				if(ht[j] < ht[i] && max1 < LIS[j]){
					LIS[i] = LIS[j] + bs[i];
					max1 = LIS[j];
				}
				else if(ht[j] > ht[i] && max2 < LDS[j]){
					LDS[i] = LDS[j] + bs[i];
					max2 = LDS[j];
				}
			}
			if(LIS[i] > max3)max3 = LIS[i];
			if(LDS[i] > max4)max4 = LDS[i];
		}
		cout<<"Case "<<t++<<". ";
		if(max3 >= max4){
			printf("Increasing (%d). Decreasing (%d).\n",max3,max4);
		}
		else printf("Decreasing (%d). Increasing (%d).\n",max4,max3);
	}
	return 0;
}