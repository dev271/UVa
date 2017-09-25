#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


int main(){
	int i,j,m,n,q,l,r,k,max1;
	vector<int> v[1000];
	int x;
	int y;
	cin>>m>>n;
	while(m&&n){
		for(i = 0; i < 1000; i++)v[i].clear();
		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				cin>>y;
				v[i].push_back(y);
			}
		}
		cin>>q;
		for(i = 0; i < q; i++){
			max1 = 0;
			cin>>l>>r;
			for(j = 0; j < m; j++){
				x = lower_bound(v[j].begin(),v[j].end(),l) - v[j].begin();
				for(k = max1; ; k++){
					if(j+k>=m || x+k>=n || v[j+k][x+k]>r)break;
					if(k+1>max1)max1 = k+1;
				}
			}
			cout<<max1<<endl;
		}
		cout<<"-"<<endl;
		cin>>m>>n;
}	
	return 0;
}