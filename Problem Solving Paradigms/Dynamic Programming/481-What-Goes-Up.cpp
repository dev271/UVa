#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> temp;
	stack<int> ans;
	int x,i,j,k,ind,pos;
	int a[100000],b[100000],c[100000];
	i = 0;
	temp.clear();
	//ans.clear();
	ind = -1;
	j = -1;
	while(cin>>c[i]){
		pos = lower_bound(temp.begin(),temp.end(),c[i]) - temp.begin();
		if(pos == temp.size())temp.push_back(c[i]);
		else temp[pos] = c[i];
		b[pos] = i;
		a[i] = pos ? b[pos - 1] : -1;
		if(pos + 1 >= j){
			j = pos + 1;
			ind = i;
		}
		i++; 
	}
	pos = ind;
	/*for(j = 0; j < i; j++){
		cout<<c[j]<<" "<<a[j]<<endl;
	}*/
	while(pos >= 0){
		ans.push(c[pos]);
		pos = a[pos];
	}
	cout<<ans.size()<<endl<<"-"<<endl;
	for(;!ans.empty();ans.pop())cout<<ans.top()<<endl;
	return 0;
}