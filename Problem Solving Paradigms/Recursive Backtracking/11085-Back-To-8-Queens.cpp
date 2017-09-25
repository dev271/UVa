#include <iostream>
using namespace std;

int minmo,p,c[100][8];
bool isSafe(int row, int col,int a[][8])
{
    int i, j;
 
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (a[row][i])
            return false;
 
    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (a[i][j])
            return false;
 
    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<8; i++, j--)
        if (a[i][j])
            return false;
 
    return true;
}
void genComb(int col,int a[][8]){
	int i,j;
	int count=0;
	if(col>=8){
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				//cout<<a[i][j]<<" ";
				if(a[i][j])c[p][j]=i;
			}
			//cout<<endl;
		}
		p++;
		return;
	}
	for(i=0;i<8;i++){
		if(isSafe(i,col,a)){
			a[i][col]=1;
			genComb(col+1,a);
			a[i][col]=0;
		}
	}
}
int main(){
	int i,j,b[8],a[8][8];
	int k=0,count;
	p=0;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++)a[i][j]=0;
	}
	genComb(0,a);
	while(cin>>b[0]){
		minmo=10;
		b[0]=b[0]-1;
		for(i=1;i<8;i++){
			cin>>b[i];
			b[i]=b[i]-1;
		}
		for(i=0;i<p;i++){
			count=0;
			for(j=0;j<8;j++){
				if(b[j]!=c[i][j])count++;
			}
			if(count<minmo)minmo=count;
		}
		cout<<"Case "<<++k<<": "<<minmo<<endl;
	}
	return 0;
}