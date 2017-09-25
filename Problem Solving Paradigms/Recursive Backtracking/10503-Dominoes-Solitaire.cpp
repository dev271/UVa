#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int flag;

void prin(vector <pair<int,int> > vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i].first<<" "<<vec[i].second<<endl;
	}
	cout<<flag;
	cout<<endl<<endl;
}
void BT(int n, vector<pair<int,int>> vec , vector<pair<int,int>> inp, bool a[]){
	//prin(vec);
	int temp;
	if(vec.size() >= n+1){
		if(inp[1].first == vec[n].second){
			flag = 1;
		}
		return;
	}
	for(int i=2; i < inp.size(); i++){
		if(a[i]){
			pair<int, int> p = vec.back();
			if(p.second == inp[i].second){
				temp = inp[i].first;
				inp[i].first = inp[i].second;
				inp[i].second = temp;
				vec.push_back(inp[i]);
				a[i] = false ; 
			BT(n,vec,inp,a);
			vec.pop_back();
			a[i] = true;
			}
			else if(p.second == inp[i].first){
				vec.push_back(inp[i]);
			
			a[i] = false ; 
			BT(n,vec,inp,a);
			vec.pop_back();
			a[i] = true;
			}
		}
	}
}
int main(){
	int m,n;
	vector<pair<int,int>> inp;
	vector<pair<int,int>> vec;
	bool a[20];
	cin>>n;
	int i;
	pair<int,int> p;
	while(n){
		inp.clear();
		vec.clear();
		flag = 0;
		for(i=0 ; i < 20 ; i++)a[i] = true;
		cin>>m;
		for(i=0;i<m+2;i++){
			cin>>p.first>>p.second;
			inp.push_back(p);
		}
		vec.push_back(inp[0]);
		BT(n,vec,inp,a);
		if(flag == 1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		cin>>n;
	}
}