#include <iostream>
#include <queue>
using namespace std;

class comp{
	public:
		bool operator()(long long int x,long long int y){
			return x>y;
		}
};
int main(){
	priority_queue<long long int,vector<long long int>,comp> pq;
	long long int n,x,sum,cost,i;
	cin>>n;
	while(n){
		cost=0;
		for (i = 0; i < n; ++i)
		{
			cin>>x;
			pq.push(x);
		}
		while(!pq.empty()){
			//cout<<pq.top()<<endl;
			sum=pq.top();
			pq.pop();
			sum=sum+pq.top();
			pq.pop();
			if(!pq.empty()){
				pq.push(sum);
			}
			cost=cost+sum;
			//cout<<sum<<" "<<cost<<endl;
		}
		cout<<cost<<endl;
		cin>>n;
		//pq.clear();
	}
	return 0;
}
