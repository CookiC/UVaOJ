#include<iostream>
#include<cstring>
using namespace std;

unsigned T=1,n,m,k,x,y,i,j,a,b;
unsigned cake[21][21][21][21];
unsigned d[21][21][21][21];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	while(scanf("%u%u%u",&n,&m,&k)!=EOF){
		memset(cake,0,sizeof(cake));
		memset(d,0xFF,sizeof(d));
		
		for(i=0;i<k;++i){
			scanf("%u%u",&x,&y);
			cake[x-1][y-1][1][1]=1;
			d[x-1][y-1][1][1]=0;
		}
		
		for(i=2;i<=n*m;++i)
			for(a=i/m?i/m:1;a<=n;++a)
				if(!(i%a)){
					b=i/a;
					for(x=0;x+a<=n;++x)
						for(y=0;y+b<=m;++y){
							if(a>1)
								cake[x][y][a][b]=cake[x][y][1][b]+cake[x+1][y][a-1][b];
							else
								cake[x][y][a][b]=cake[x][y][a][1]+cake[x][y+1][a][b-1];
							if(cake[x][y][a][b]<=1){
								d[x][y][a][b]=0;
								continue;
							}
							unsigned sum;
							for(k=1;k<a;++k)
								if(cake[x][y][k][b]&&cake[x+k][y][a-k][b]){
									sum=d[x][y][k][b]+d[x+k][y][a-k][b]+b;
									d[x][y][a][b]=d[x][y][a][b]>sum?sum:d[x][y][a][b];
								}
							for(k=1;k<b;++k)
								if(cake[x][y][a][k]&&cake[x][y+k][a][b-k]){
									sum=d[x][y][a][k]+d[x][y+k][a][b-k]+a;
									d[x][y][a][b]=d[x][y][a][b]>sum?sum:d[x][y][a][b];
								}
						}
				}
		printf("Case %u: %u\n",T++,d[0][0][n][m]);
	}
	return 0;
}

