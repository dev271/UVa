#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
	multiset <int> green;
	multiset <int> blue;
	int test,n,ba,i,j,nb,ng,x;
	multiset<int>::iterator g;
	multiset<int>::iterator b;
	multiset<int>::iterator it1;
	multiset<int>::iterator it2;
	vector <int> gr;
	vector <int> bl;
	cin>>test;
	while(test--){
		green.clear();
		blue.clear();
		cin>>ba>>ng>>nb;
		for(i=0;i<ng;i++){
			cin>>x;
			green.insert(x);
		}
		for(i=0;i<nb;i++){
			cin>>x;
			blue.insert(x);
		}
		
		//it1--;it2--;
		while(!green.empty() && !blue.empty()){
			g=green.end();b=blue.end();	
			g--;b--;
			for(i=0;i<ba;i++){
				it1=g;it2=b;
				if(!green.empty() && !blue.empty()){
					g--;b--;
				}
				if(*it1<*it2){
					bl.push_back(*it2-*it1);
					green.erase(it1);
					blue.erase(it2);
				}
				else if(*it1>*it2){
					gr.push_back(*it1-*it2);
					green.erase(it1);
					blue.erase(it2);
				}
				else{
					green.erase(it1);
					blue.erase(it2);
				}

				if(green.empty() || blue.empty()){
					break;
				}
			}
			while(!bl.empty()){
				blue.insert(bl.back());
				bl.pop_back();
			}
			while(!gr.empty()){
				green.insert(gr.back());
				gr.pop_back();
			}
		}
		if(!green.empty() && blue.empty()){
			g=green.end();
			g--;
			it1=green.begin();//it1--;
			cout<<"green wins"<<endl;
			while(g!=green.begin()){
				cout<<*g<<endl;
				g--;
			}
			cout<<*g<<endl;
		}
		else if(green.empty() && !blue.empty()){
			b=blue.end();
			b--;
			cout<<"blue wins"<<endl;
			it2=blue.begin();//it2--;
			while(b!=blue.begin()){
				cout<<*b<<endl;
				b--;
			}
			cout<<*b<<endl;
		}
		else
			cout<<"green and blue died"<<endl;
		if(test!=0)
			cout<<endl;
	}
	return 0;
}
