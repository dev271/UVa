#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	int k,i,j,l,m,max_dist,min_dist,x,y,dist;
	char c;
	vector<pair<int,int>> v1;
	vector<pair<int,int>> v3;
	while(cin>>k){
		v1.clear();v3.clear();
		max_dist=-1;
		for(i=0;i<k;i++){
			for(j=0;j<k;j++){
				cin>>c;
				if(c=='1')
					v1.push_back(make_pair(i,j));
				else if(c=='3')
					v3.push_back(make_pair(i,j));
			}
		}
		x=v1.size();y=v3.size();
		for(i=0;i<x;i++){
			min_dist=2*k;
			for(j=0;j<y;j++){
				if((abs(v3[j].first-v1[i].first)+abs(v3[j].second-v1[i].second))<min_dist)
					min_dist=(abs(v3[j].first-v1[i].first)+abs(v3[j].second-v1[i].second));
			}
			if(min_dist>max_dist)
				max_dist=min_dist;
		}
		cout<<max_dist<<endl;
	}
	return 0;
}