#include <iostream>
#include <sstream>
#include <cstring>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
	int a[5],n,max,ans;
	stringstream s;
	cin>>n;
	pair<map <string,int>::iterator,bool> ret;
	while(n){	
		max=0;ans=0;
		map <string,int> mp;
		map <string,int>::iterator it;
		for (int i = 0; i < n; ++i)
		{
			s.str("");
			cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
			sort(a,a+5);
			s<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4];
			//cout<<s.str()<<endl;
			ret=mp.insert(pair<string,int>(s.str(),1));
			if(ret.second==false){
				ret.first->second=ret.first->second+1;
			}
			
		}
		it = mp.begin();
			max=it->second;
			for (; it != mp.end(); ++it)
			{
				if(it->second > max)
					max=it->second;
			}
			
		for(it=mp.begin();it != mp.end(); ++it)
			{
				if(it->second==max)
					ans += max;
			}
		cout<<ans<<endl;
		cin>>n;
	}
	return 0;
}

