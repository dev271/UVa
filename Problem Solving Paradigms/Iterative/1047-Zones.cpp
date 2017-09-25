#include <iostream>
#include <vector>
using namespace std;

int a[100][100],max1;
int ans1[100];
int do_stuff(int b[],int m,vector<int> v,int p){
	int i,j,k;	
	for(i=0;i<p;i++){
		for(j=0;j<m;j++){
			for(k=1;k<a[j][0]+1;k++){
				if(a[j][k]==v[i])a[j][a[j][0]+2]++;
			}
		}
	}
	int ans=0;
	for(i=0;i<p;i++){
		ans=ans+b[v[i]];
	}
	for(i=0;i<m;i++){
		if(a[i][a[i][0]+2]!=0)
		ans=ans-a[i][a[i][0]+1]*(a[i][a[i][0]+2]-1);
	}
	//cout<<ans<<endl;
	return ans;
}
void subset(int arr[], int size, int left, int index, vector<int> &v,int m,int p){
    int i,x;
    if(left==0){
    	/*for(i=0;i<v.size();i++){
			cout<<v[i]<<" ";
		} 
		cout<<endl;*/
		for(i=0;i<m;i++){
			a[i][a[i][0]+2]=0;
		} 
		x=do_stuff(arr,m,v,p);
		if(x>max1){
			for(i=0;i<p;i++){
				ans1[i]=v[i];
			}  
			max1=x;
		}
		//cout<<max1;   
		//cout<<endl;
        return;
    }
    for(i=index; i<size;i++){
        v.push_back(i);
        subset(arr,size,left-1,i+1,v,m,p);
        v.pop_back();
    }

}   
int main(){
	int n,p,m,b[100],i,j,o=1;
	vector<int> v;
	cin>>n>>p;
	while(n && p){
		v.clear();
		max1=0;
		for(i=0;i<n;i++){
			cin>>b[i];
		}
		cin>>m;
		for(i=0;i<m;i++){
			cin>>a[i][0];
			for(j=1;j<a[i][0]+1;j++){
				cin>>a[i][j];a[i][j]--;
			}
			cin>>a[i][a[i][0]+1];
		}
		subset(b,n,p,0,v,m,p);
		cout<<"Case Number  "<<o<<endl<<
			  "Number of Customers: "<<max1<<endl<<
			  "Locations recommended:";
		for(i=0;i<p;i++){
			cout<<" "<<ans1[i]+1;
		}
		cout<<endl<<endl;
		cin>>n>>p;
		o++;
	}
	return 0;
}