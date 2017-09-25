#include <iostream>
#include <vector>
#include <set>
using namespace std;

int flag;
set<vector<int>> powerSet;
void work(int A[], bool a[], int sumReq, int low, int n){
	int i,j,ind,sum;
	vector<int> vec;
	if(low>=n){
		sum = 0;
		for(i=0;i<n;i++)
			if(a[i])sum = sum + A[i];
		if(sum == sumReq){
			for(i=0;i<n;i++){
				if(a[i]){
					vec.push_back(A[i]);
				}
			}
			powerSet.insert(vec);
		}
		return ;
	}
	a[low] = false;
	work(A,a,sumReq,low+1,n);
	a[low] = true;
	work(A,a,sumReq,low+1,n);
	return;
}
int main(){
	int sumReq,sum,n,x,t,p,l;
	int A[15];
	set<vector<int>>::iterator it;
	bool a[15];
	cin>>sumReq;
	while(sumReq){
		cin>>n;
		powerSet.clear();
		for(x=0;x<n;x++)cin>>A[x];
		cout<<"Sums of "<<sumReq<<":"<<endl;
		work(A,a,sumReq,0,n);
		if(powerSet.empty()){
			cout<<"NONE"<<endl;
			cin>>sumReq;
			continue;
		}
		it = powerSet.end();
		it--;
		for(;it!=powerSet.begin();it--){
			const vector<int>& j=(*it);
			t = j.size();
			for(p=0;p<t;p++){
				if(p!=t-1)cout<<j[p]<<"+";
				else cout<<j[p]<<endl;
			}
		}
		it=powerSet.begin();
		const vector<int>& j=(*it);
		t = j.size();
		for(p=0;p<t;p++){
			if(p!=t-1)cout<<j[p]<<"+";
			else cout<<j[p]<<endl;
		}
		cin>>sumReq;
	}
	return 0;
}