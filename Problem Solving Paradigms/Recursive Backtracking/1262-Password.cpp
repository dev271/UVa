#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
	int test,k,i,j,y;
	char a[5][6],b[5][6];
	int q,w,e,r,t;
	vector<int> vec[5];
	cin>>test;
	bool flag;
	bool flag1[125];
	while(test--){
		cin>>k;
		
		flag = true;
		q=0;w=0;e=0;r=0;t=0;
		for(i=0;i<5;i++)vec[i].clear();
		for(j=0;j<6;j++){
			for(i=0;i<5;i++){
				cin>>a[i][j];
			}
		}
		for(j=0;j<6;j++){
			for(i=0;i<5;i++){
				cin>>b[i][j];
			}
		}
		for(i=0;i<5;i++){
			sort(a[i],a[i]+6);
			sort(b[i],b[i]+6);
		}
		for(i=0;i<5;i++){
			for(j=0;j<125;j++){
				flag1[j]=false;
			}
			for(j=0;j<6;j++){
				if(flag1[int(a[i][j])])continue;
				else flag1[int(a[i][j])]= true;
				for(y=0;y<6;y++){
					if(a[i][j]==b[i][y]){vec[i].push_back(j);break;}
				}
			}
		}
		/*for(i=0;i<6;i++){
			for(j=0;j<5;j++){
				cout<<a[j][i];
			}
			cout<<endl;
		}
		cout<<endl;
		for(i=0;i<6;i++){
			for(j=0;j<5;j++){
				cout<<b[j][i];
			}
			cout<<endl;
		}
		for(i=0;i<5;i++){
			for(j=0;j<vec[i].size();j++){
				cout<<vec[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;*/
		y=1;

		while(y!=k){
			t++;
			if(t>=vec[4].size()){
				r++;
				t=0;
				if(r>=vec[3].size()){
					r=0;
					e++;
					if(e>=vec[2].size()){
						w++;
						e=0;
						if(w>=vec[1].size()){
							w=0;q++;
							if(q>=vec[0].size()){
								flag=false;
							}
						}
					}
				}
			}
			y++;
		}
		if(q>=vec[0].size()||w>=vec[1].size()||e>=vec[2].size()||r>=vec[3].size()||t>=vec[4].size())flag=false;
		if(flag){
			cout<<a[0][vec[0][q]]<<a[1][vec[1][w]]<<a[2][vec[2][e]]<<a[3][vec[3][r]]<<a[4][vec[4][t]]<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}