#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;
int main(){
	vector <string> vs;
	vector <pair<int,int>>vp;
	int test,n,l,h,q,x,i,j,flag,index;
	string str;
	cin>>test;
	while(test--){
		vs.clear();vp.clear();
		cin>>n;
		for(i=0;i<n;i++){
			cin>>str;
			cin>>l>>h;
			vs.push_back(str);
			vp.push_back(make_pair(l,h));
		}
		cin>>q;
		for(i=0;i<q;i++){
			flag=0;
			cin>>x;
			for(j=0;j<n;j++){
				if(vp[j].first<=x && vp[j].second>=x){
					flag++;
					index=j;
				}
			}
			if(flag==0 || flag>1){
				cout<<"UNDETERMINED"<<endl;
			}
			else
				cout<<vs[index]<<endl;
		}
		if(test!=0)
			cout<<endl;
	}	
	return 0;
}