#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,test,c[2100][3],i,j,max1,max2,max3;
	cin>>test;
	while(test--){
		cin>>n;
		if(n==0){cout<<"0"<<endl;continue;}
		for(i = 0; i < n; i++){
			cin>>c[i][0];
		}
		c[n-1][1] = 1;
		c[n-1][2] = 1;
		max3 = 1;
		for(i = n - 2; i >= 0; i--){
			max1 = -1;max2 = -1;
			c[i][1] = 1;
			c[i][2] = 1;
			for(j = i + 1; j < n; j++){
				if(c[i][0] > c[j][0] && max1 < c[j][1]){
					max1 = c[j][1];
					c[i][1] = c[j][1] + 1;
				}
				else if(c[i][0] < c[j][0] && max2 < c[j][2]){
					max2 = c[j][2];
					c[i][2] = c[j][2] + 1;
				}
			}
			//cout<<c[i][0]<<" "<<c[i][1]<<" "<<c[i][2]<<endl;
			if(c[i][1] + c[i][2] - 1 > max3)max3 = c[i][1] + c[i][2] - 1;
		}
		cout<<max3<<endl;
	}
}