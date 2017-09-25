#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int main(){
	int test,n,t,m,x,time,i,j,temp1,k;
	cin>>test;
	bool boo;
	string s,bank;
	vector<char> vec1;
	while(test--){
		vec1.clear();
		time=0;
		bank="left";
		//cout<<bank<<endl;
		queue <int> left;
		queue <int> right;
		queue <int> le;
		queue <int> ri;
		cin>>n>>t>>m;
		temp1=m;
		while(temp1--){
			cin>>x>>s;
			if(s=="left"){
				left.push(x);
				vec1.push_back('l');
			}
			else{
				right.push(x);
				vec1.push_back('r');
			}
		}
		for(;;){
			if(bank=="left"){
				if(!left.empty()){
					if(left.front()<=time){
						j=0;
						while(j<n && left.front()<=time && !left.empty()){
							left.pop();
							//cout<<"A"<<endl;
							le.push(time+t);
							boo=true;
							bank="right";
							j++;
						}
						if(boo)
							time=time+t;
						//if(left.empty()){
						//	left.push(20000);
						//}
					}
					else if(right.front()<=time && !right.empty()){
						//cout<<"B"<<endl<<right.empty()<<endl;
							time = time+t;
							bank="right";
					}
					else if(right.front()<left.front() && !right.empty()){
						//cout<<"C"<<endl;
						time=right.front()+t;
						bank="right";
					}
					else if(right.front()>=left.front()){
						//cout<<"D"<<endl;
						time=left.front();
					}
					else
						time=left.front();
				}
				else{
					//cout<<"E"<<endl;
					if(right.front()<=time){
						time=time+t;
						bank="right";
					}
					else{
						time=right.front()+t;
						bank="right";
					}
				}
			}
			else{
				if(!right.empty()){
					if(right.front()<=time){
						j=0;
						while(j<n && right.front()<=time && !right.empty()){
							right.pop();
							//cout<<"F"<<endl;
							ri.push(time+t);
							boo=true;
							bank="left";
							j++;
						}
						if(boo)
							time=time+t;
						//if(right.empty()){
						//	right.push(20000);
						//}
					}
					else if(left.front()<=time && !left.empty()){
						time = time+t;
						//cout<<"G"<<endl;
						bank="left";
					}
					else if(left.front()<right.front() && !left.empty()){
						time=left.front()+t;
						//cout<<"H"<<endl;
						bank="left";
					}
					else if(left.front()>=right.front()){
						time=right.front();
						//cout<<"I"<<endl;
					}
					else
						time=right.front();
				}
				else{
					//cout<<"J"<<endl;
					if(left.front()<=time){
						time=time+t;
						bank="left";
					}
					else{
						time=left.front()+t;
						bank="left";
					}
				}
			}
			//cout<<right.empty()<<left.empty()<<endl;
			if(right.empty() && left.empty()){
				for(k=0;k<m;k++){
					if(vec1[k]=='l'){
						cout<<le.front()<<endl;
						le.pop();
					}
					else{
						cout<<ri.front()<<endl;
						ri.pop();
					}
				}
				break;
			}
		}
		if(!(test==0))
			cout<<endl;
	}
	return 0;
}
