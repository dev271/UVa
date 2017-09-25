#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;
int min4(int a,int b,int c,int d,int e){
	int min3=a;
	if(b<min3)
		min3=b;
	if(c<min3)
		min3=c;
	if(d<min3)
		min3=d;
	if(e<min3)
		min3=e;
	return min3;
}
int main(){
	long long int n,k,x,y,pop,mind,i,j,l,m,o,dist,min_dist,q,w;
	int p[5];
	long long int a[5][5];
	cin>>n;
	while(n--){
		cin>>o;
		min_dist=1000000000000000000;
		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
				a[i][j]=0;
			}
		}
		for(i=0;i<o;i++){
			cin>>x>>y>>pop;
			a[x][y]=pop;
		}
		for(i=0;i<25;i++){
			for(j=i+1;j<25;j++){
				for(k=j+1;k<25;k++){
					for(l=k+1;l<25;l++){
						for(m=l+1;m<25;m++){
							dist=0;
							for(q=0;q<5;q++){
								for(w=0;w<5;w++){
									dist=dist+min4((abs(q-i/5)+abs(w-i%5)),(abs(q-j/5)+abs(w-j%5)),(abs(q-k/5)+abs(w-k%5)),(abs(q-l/5)+abs(w-l%5)),(abs(q-m/5)+abs(w-m%5)))*a[q][w];
								}
							}
							if(dist<min_dist){
								min_dist=dist;
								p[0]=i;
								p[1]=j;
								p[2]=k;
								p[3]=l;
								p[4]=m;
							}
						}
					}
				}
			}
		}
		cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<" "<<p[3]<<" "<<p[4]<<endl;
	}
	return 0;
}