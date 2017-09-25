#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int main(){
	int f,r,i,j;
	double d1,d2,max;
	int fr[12],re[12];
	priority_queue<double> pq;
	cin>>f;
	while(f){
		cin>>r;
		max=0;
		for(i=0;i<f;i++){
			cin>>fr[i];
		}
		for (i = 0; i < r; ++i)
		{
			cin>>re[i];
		}
		for(i=0;i<f;i++){
			for(j=0;j<r;j++){
				pq.push((double(re[j]))/fr[i]);
			}
		}
		d2=pq.top();
		pq.pop();
		while(!pq.empty()){
			d1=pq.top();
			if((d2/d1)>max)
				max=d2/d1;
			d2=d1;
			pq.pop();
		}
		printf("%.2f\n",max);
		cin>>f;
	}
}