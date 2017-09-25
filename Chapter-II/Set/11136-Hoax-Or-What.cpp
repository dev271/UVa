#include <iostream>
#include <set>
using namespace std;

int main(){
	long long int n,k,sum,i,x,test;
	multiset<int> p;
	multiset<int>::iterator it1;
	multiset<int>::iterator it2;
	cin>>n;
	while(n){
		p.clear();
		sum=0;
		test=n;
		while(test--){
			cin>>k;
			for (i = 0; i < k; ++i)
			{
				cin>>x;
				p.insert(x);
			}
			if(!p.empty()){
				it1=p.end();
				it1--;
				it2=p.begin();
				sum=sum+(*it1-*it2);
				p.erase(it1);
				p.erase(it2);
			}
		}
		cout<<sum<<endl;
		cin>>n;
	}
	return 0;
}