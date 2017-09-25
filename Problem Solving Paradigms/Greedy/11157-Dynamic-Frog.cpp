#include <bits/stdc++.h>
using namespace std;

int main(){
	int t=1,i,dist,test,n,d;
	char ch;
	string s;
	pair<int,char> pa;
	vector<pair<int,char>> vp;
	cin>>test;
	while(test--){
		cin>>n>>d;
		dist = -1;
		pa.first = 0;
		pa.second = 'B';
		vp.clear();
		cin.ignore();
		vp.push_back(pa);
		for(i = 0; i < n; i++){
			cin>>pa.second>>ch>>pa.first;
			vp.push_back(pa);
		}
		pa.first = d;
		pa.second = 'B';
		vp.push_back(pa);
		sort(vp.begin(),vp.end());
		//for(i = 0; i < vp.size(); i++){
		//	cout<<vp[i].first<<" ";
		//}
		//cout<<endl;
		dist = vp[1].first - vp[0].first;
		for(i = 1; i < vp.size() - 1; i++){
			if(vp[i].second == 'S'){
				if(vp[i+1].first-vp[i-1].first > dist)dist = vp[i+1].first-vp[i-1].first;
			}
			else
				if(vp[i+1].first - vp[i].first > dist)dist = vp[i+1].first - vp[i].first;
		}
		printf("Case %d: %d\n",t,dist);
		t++;
	}
}