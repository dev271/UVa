#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

bool has11(int x){
	return (x && !(x & (x-1)))||(x==1);
}
vector <pair <int,int> > vec;
int work(vector <pair <int,int> > vec,int wt[]){
	int i,j,mx=-1;
	int pot[20000]={0};
	for(i=0;i<vec.size();i++){
		pot[vec[i].first] += wt[vec[i].second];
		pot[vec[i].second] += wt[vec[i].first];
	}
	for(i=0;i<vec.size();i++){
		if(mx<(pot[vec[i].first]+pot[vec[i].second]))
			mx=pot[vec[i].first]+pot[vec[i].second];
	}
	return mx;
}
int main(){
	int n,i,j,x;
	int wt[20000];
	while(scanf("%d",&n)){
		x=pow(2,n);
		vec.clear();
		for(i=0;i<x;i++){
			for(j=i+1;j<x;j++){
				if(has11(i ^ j))
					vec.push_back(make_pair(i,j));
			}
		}
		for(i=0;i<x;i++){
			scanf("%d",&wt[i]);
		}
		cout<<work(vec,wt)<<endl;;
	}
}
