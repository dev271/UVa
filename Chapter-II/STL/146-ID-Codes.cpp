#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
	string s,x,y;
	int i,j,k,l,flag;
	char temp;
	cin>>s;
	while(s!="#"){
		flag=1;
		x.clear();
		for(i=s.size()-1;i>0;i--){
			for(j=i-1;j>=0;j--){
				if(s[i]>s[j]){
					x.push_back(s[i]);
					//cout<<x<<endl;
					s.insert(j,x);
					s.erase(i+1,1);
					sort(s.begin()+i,s.end());
					cout<<s<<endl;
					flag=0;
					break;
				}
			}
			if(!flag)
				break;
		}
		if(flag)
			cout<<"No Successor"<<endl;
		cin>>s;
	}
	return 0;
}
