#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main(){
	string s;
	bool t;
	cin>>s;
	int i,j,count,k=1;
	while(s!="end"){
		stack <char> st[30];
		count=0;
		for(i=s.size()-1;i>=0;i--){
			j=0;
			t=true;
			while(!st[j].empty()){
				if(st[j].top()<=s[i]){
					st[j].push(s[i]);
					//cout<<j<<endl;
					t=false;
					break;
				}
				j++;
			}
			if(t){
				//cout<<"lol";
				st[j].push(s[i]);
			}
			
		}
		count=0;
		while(!st[count].empty())
			count++;
		cout<<"Case "<<k<<": "<<count<<endl;
		k++;
		cin>>s;
	}
	return 0;
}