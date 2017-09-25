#include <iostream>
#include <stack>
using namespace std;

int main(){
	stack<int> s;
	int n,a,i,j,k,flag1;
	int flag[1010];
	char c;
	cin>>n;
	while(n){
		cin>>c;
		if(c=='0'){
			cin>>n;
			cout<<endl;
			continue;
		}
		else
			cin.putback(c);
		flag1=1;
		for(k=0;k<1010;k++)
			flag[k]=0;
		for (i = 0; i < n; ++i)
		{
			cin>>a;
			if(flag[a]){
				if(s.top()==a)
					s.pop();
				else{
					flag1=0;
					continue;
				}
			}
			else{
				flag[a]=1;
				for(j=1;j<a;j++){
					if(flag[j])
						continue;
					s.push(j);
					flag[j]=1;
				}
			}
			
		}
		while(!s.empty()){
				s.pop();
			}
		if(flag1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
