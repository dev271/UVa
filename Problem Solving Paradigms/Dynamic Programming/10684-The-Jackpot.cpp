#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int x;
	int sum,max;
	cin>>n;
	while(n){
		sum = 0; max = -1000000000;
		for(int i = 0; i < n ; i++){
			cin>>x;
			sum += x;
			if(sum > max) max = sum;
			if(sum < 0) sum = 0;
		}
		if(sum <= 0)cout<<"Losing streak."<<endl;
		else cout<<"The maximum winning streak is "<<max<<"."<<endl;
		cin>>n;
	}
	return 0;
}
