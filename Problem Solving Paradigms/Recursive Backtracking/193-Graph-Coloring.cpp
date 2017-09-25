#include <iostream>
#include <vector>
using namespace std;

int max1;vector<int>ans;
void work(vector<vector<int>> vec,int ind){
	int i,count=0,j;
	if(ind == vec.size()-1){
		for(i = 1; i < vec.size(); i++){
			if (vec[i][0]==1)
			{
				count++;

			}
			
		}
		if(count>=max1) {max1 = count;
				ans.clear();
				for(int j=1;j<vec.size();j++){
					if(vec[j][0])ans.push_back(j);
				}
				//cout<<endl;
			}
		return ;
	}
	bool switc[110];
	for(i=0;i<110;i++)switc[i]=false;
	if(vec[ind][0]){
		for(i=1;i<vec[ind].size();i++){
			if(vec[vec[ind][i]][0]){
				vec[vec[ind][i]][0]=0;
				switc[i]=true;
			}
		}
		work(vec,ind+1);
		for(i=1;i<vec[ind].size();i++){
			if(vec[vec[ind][i]][0]==0 && switc[i]){
				vec[vec[ind][i]][0]=1;
				switc[i]=false;
			}
		}
		vec[ind][0]=0;
	}
	work(vec,ind+1);
	return;
}
int main(){
	int m,n,k,i,j,l,r,x;
	vector<vector<int>> vec;
	cin>>m;
	while(m--){
		vec.clear();
		ans.clear();	
		max1=0;
		scanf("%d %d",&n,&k);
		for(i=0;i<n+1;i++){
			vector<int> v;
			v.push_back(1);
			vec.push_back(v);
		}
		for(i=0;i<k;i++){
			scanf("%d %d",&l,&r);
			vec[l].push_back(r);
			vec[r].push_back(l);
		}
		work(vec,1);
		printf("%d\n",max1);
		x=ans.size();
		for(i=0;i<x;i++)if(i!=x-1)printf("%d ",ans[i]);
			else printf("%d\n",ans[i]);
	}
	return 0;
}