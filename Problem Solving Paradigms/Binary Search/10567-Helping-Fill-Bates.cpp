#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> vec[125];
	string s;
		int i,j,prev;
	for(i=0;i<125;i++)vec[i].clear();
	cin>>s;
	int k;
	cin>>k;

	string a;
	bool flag;
	vector<int>::iterator it;
	for(i = 0; i < s.size(); i++){
		vec[int(s[i])].push_back(i);
	}
	int l,r;
	for(i = 0; i < k;i++){
		cin>>a;
		flag = true;
		prev = -1;
		for(j=0;j<a.size();j++){
			it = lower_bound(vec[int(a[j])].begin(),vec[int(a[j])].end(),++prev);
			if(it == vec[int(a[j])].end()){
				flag = false;
			}
			prev = *it;
			if(j == 0)l = vec[int(a[j])][0];
			if(j == a.size()-1)r = prev;
		}
		if(flag)cout<<"Matched "<<l<<" "<<r<<endl;
		else cout<<"Not matched"<<endl;
	}
}
