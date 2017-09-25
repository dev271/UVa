#include <iostream>
using namespace std;

int main(){
	int i,k,as[15],a,b,c,d,e,f;
	cin>>k;
	while(k){
		for(i=0;i<k;i++){
			cin>>as[i];
		}
		for(a=0;a<=k-6;a++){
			for(b=a+1;b<=k-5;b++){
				for(c=b+1;c<=k-4;c++){
					for(d=c+1;d<=k-3;d++){
						for(e=d+1;e<=k-2;e++){
							for(f=e+1;f<=k-1;f++){
								cout<<as[a]<<" "<<as[b]<<" "<<as[c]<<" "<<as[d]<<" "<<as[e]<<" "<<as[f]<<endl;
							}
						}
					}
				}
			}
		}
		cin>>k;
		if(k!=0)
			cout<<endl;
	}	
	return 0;
}