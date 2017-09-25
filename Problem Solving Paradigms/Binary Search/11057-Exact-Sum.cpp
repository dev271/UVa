#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> vec;
	vector<int>::iterator it;
	int i,n,m,x,l,r;
	while(cin>>n){
		vec.clear();
		for(i = 0; i<n ; i++){
			cin>>x;
			vec.push_back(x);
		}
		sort(vec.begin(),vec.end());
		cin>>m;
		for(i=0;i<n-1;i++){
			x = m - vec[i];
			if(*lower_bound(vec.begin() + i + 1, vec.end(), x) == x){
				l = vec[i] ;
				r = x;
			}
		}
		cout<<"Peter should buy books whose prices are "<<l<<" and "<<r<<"."<<endl<<endl;
	}
}