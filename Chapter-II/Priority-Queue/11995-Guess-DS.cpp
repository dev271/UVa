#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <stack>
using namespace std;

class comp{
	public:
		bool operator()(long long int x,long long int y){
			return x<y;
		}
};
int main(){
	priority_queue<int,vector<int>> pq;
	queue <int> q;
	stack <int> s;
	int flag1,flag2,flag3;
	int n,x,y;
	while(cin>>n){
		flag1=1;flag2=1;flag3=1;
		for (int i = 0; i < n; ++i)
		{
			cin>>x;
			if(x==1){
				cin>>y;
				pq.push(y);
				q.push(y);
				s.push(y);
			}
			else {
				cin>>y;
				if(flag1){
					if(pq.empty() || pq.top()!=y){
						flag1=0;
					}
					else
						pq.pop();
				}
				if(flag2){
					if(q.empty() || q.front()!=y){
						flag2=0;
					}
					else
						q.pop();
				}
				if(flag3){
					if(s.empty() || s.top()!=y){
						flag3=0;
					}
					else
						s.pop();
				}
			}
		}
		if((flag1+flag2+flag3)>1)
			cout<<"not sure"<<endl;
		else if(flag1==1)
			cout<<"priority queue"<<endl;
		else if(flag2==1)
			cout<<"queue"<<endl;
		else if(flag3==1)
			cout<<"stack"<<endl;
		else
			cout<<"impossible"<<endl;
		while(!pq.empty()){
			pq.pop();
		}
		while(!q.empty()){
			q.pop();
		}
		while(!s.empty()){
			s.pop();
		}
	}
	return 0;
}	