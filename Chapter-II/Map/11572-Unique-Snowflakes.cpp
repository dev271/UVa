#include <iostream>
#include <map>
#include <utility>
using namespace std;
int a[1000010];
int main(){
	int n,test,x,count,t,i,j,k,low,high;
	int max=0;
	cin>>test;
	map <int , int> mp;
	while(test--){
		max=0;
		cin>>n;
		count=0;
		pair<map <int,int>::iterator,bool> ret;
		ret.second=true;
		t=0;
		j=0;i=0;low=0;high=0;
		mp.clear();
		while(j<n){
			cin>>x;
			a[j]=x;
			ret=mp.insert(pair<int,int> (x,j));
			if(ret.second==false){
				if((j-i)>max){
					max=j-i;
					low=i;
					high=j;
				}
				t=mp[x]+1;
				for(k=i;k<=mp[x];k++){
					mp.erase(a[k]);
				}
				mp.erase(x);
				i=t;
				//cout<<" "<<i<<endl;
				ret=mp.insert(pair<int,int> (x,j));
				//cout<<ret.second<<endl;
			}
			
			j++;
			if(j==n){
				if(j-i>max){
					max=j-i;
					low=i;high=j;
				}
			}
		}
		cout<<max<<endl;
	}
	return 0;
}