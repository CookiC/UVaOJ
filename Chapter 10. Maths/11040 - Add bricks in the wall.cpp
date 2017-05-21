#include<cstdio>
#include<cstring>

int T;
int wall[9][9];
unsigned i,j;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		for(i=0;i<9;i+=2)
			for(j=0;j<=i;j+=2)
				scanf("%d",&wall[i][j]);
		for(i=0;i<7;i+=2)
			for(j=0;j<=i;j+=2)
				wall[i+2][j+1]=(wall[i][j]-wall[i+2][j]-wall[i+2][j+2])/2;
		for(i=1;i<8;i+=2)
			for(j=0;j<=i;++j)
				wall[i][j]=wall[i+1][j]+wall[i+1][j+1];
		for(i=0;i<9;++i){
			for(j=0;j<i;++j)
				printf("%d ",wall[i][j]);
			printf("%d\n",wall[i][i]);
		}
	}
	return 0;
}

