#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

int a[5000];
class comp{
	public:
		bool operator()(pair<int,int> n1,pair<int,int> n2){
			if(n1.second==n2.second)
				return n1.first>n2.first;
			return n1.second>n2.second;
		}
};
int main(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
	pair <int,int> p;
	int k;
	string s;
	cin>>s;
	while(s!="#"){
		cin>>p.first>>p.second;
		a[p.first]=p.second;
		pq.push(p);
		cin>>s;	
	}
	cin>>k;
	for (int i = 0; i < k; ++i)
	{
		p=pq.top();
		pq.pop();
		cout<<p.first<<endl;
		p.second=p.second+a[p.first];
		pq.push(p);
	}
	return 0;
}
