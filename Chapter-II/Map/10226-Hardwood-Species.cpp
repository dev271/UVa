#include <iostream>
#include <map>
#include <cstring>
#include <utility>
using namespace std;
int main(){

	int test,i,j,n;
	float x;
	string s;
	cin>>test;
	scanf("\n\n");
	pair <map<string,int>::iterator,bool> ret;
	while(test--){
		n=0;
		map <string,int> mp;
		map <string,int>::iterator it;
		getline(cin,s);
		while(s.size()!=0){
			ret=mp.insert(pair<string,int> (s,1));
			if(ret.second==false){
				ret.first->second=ret.first->second+1;
			}
			n++;
			getline(cin,s);
		}
		for (it = mp.begin(); it != mp.end(); ++it)
		{
			cout<<it->first<<" ";
			x=(it->second*100.00/n);
			printf("%.4f\n",x);
		}
		//while()
		if(test!=0)
			cout<<endl;
		//scanf("\n\n");
	}
	return 0;
}
