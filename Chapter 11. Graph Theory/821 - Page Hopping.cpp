#include<cstdio>
#include<cstring>
#define INF 0xFFFFFFFF

unsigned i,j,k,x,y,n,sum,T;
unsigned a[110],d[110][110];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	T=0;
	while(scanf("%u%u",&x,&y)!=EOF&&x){
		memset(a,0xFF,sizeof(a));
		memset(d,0xFF,sizeof(d));
		a[x]=0;a[y]=1;
		n=2;
		
		d[0][1]=1;
		while(scanf("%u%u",&x,&y)!=EOF&&x){
			if(a[x]==INF)
				a[x]=n++;
			if(a[y]==INF)
				a[y]=n++;
			d[a[x]][a[y]]=1;
		}
		for(k=0;k<n;++k)
			for(i=0;i<n;++i)
				for(j=0;j<n;++j)
					if(d[i][k]<INF&&d[k][j]<INF&&d[i][j]>d[i][k]+d[k][j])
						d[i][j]=d[i][k]+d[k][j];
		
		sum=0;
		for(i=0;i<n;++i)
			for(j=0;j<n;++j)
				if(i!=j)
					sum+=d[i][j];
				
		printf("Case %u: average length between pages = %.3lf clicks\n",++T,(double)sum/(n*n-n));
	}
	return 0;
}

