#include <iostream>
#include <queue>
using namespace std;

int main(){
	int test,l,m,i,j,temp1,x,ans,sum;
	cin>>test;
	bool boo;
	string s,bank;
	vector<char> vec1;
	while(test--){
		vec1.clear();
		bank="left";
		ans=0;
		queue <int> left;queue <int> right;
		cin>>l>>m;
		l=l*100;
		temp1=m;
		while(temp1--){
			cin>>x>>s;
			if(s=="left")
				left.push(x);
			else
				right.push(x);
		}
		for(;;){
			boo=false;
			if(bank=="left"){
				if(!left.empty()){
					sum=left.front();
					while(sum<=l && !left.empty()){
						left.pop();
						sum=sum+left.front();
					}
				}
				ans++;
				bank="right";
			}
			else{
				if(!right.empty()){
					sum=right.front();
					while(sum<=l && !right.empty()){
						right.pop();
						sum=sum+right.front();
					}
				}
				ans++;
				bank="left";
			}
			if(left.empty() && right.empty()){
				break;
			}		
		}
		cout<<ans<<endl;
	}
	return 0;
}