#include <iostream>
using namespace std;

int main(){
	long long int s,d,a,b;
	while(cin>>s>>d){
		if(4*s-d<0){
			if(10*s-2*d>0)cout<<10*s-2*d<<endl;
			else cout<<"Deficit"<<endl;
		}
		else if(3*s-2*d<0){
			if(8*s-4*d>0)cout<<8*s-4*d<<endl;
			else cout<<"Deficit"<<endl;
		}
		else if(2*s-3*d<0){
			if(6*s-6*d>0)cout<<6*s-6*d<<endl;
			else cout<<"Deficit"<<endl;
		}
		else if(s-4*d<0){
			if(3*s-9*d>0)cout<<3*s-9*d<<endl;
			else cout<<"Deficit"<<endl;
		}
		else cout<<"Deficit"<<endl;
	}
	return 0;
}
