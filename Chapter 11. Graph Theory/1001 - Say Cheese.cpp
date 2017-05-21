#include<cstdio>
#include<cmath>

int n;
double res;
int x[110],y[110],z[110],r[110];
double d[110][110];
unsigned i,j,k,T;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	T=0;
	while(scanf("%d",&n)!=EOF&&n>=0){
		for(i=0;i<n;++i)
			scanf("%d%d%d%u",&x[i],&y[i],&z[i],&r[i]);
		scanf("%d%d%d%d%d%d",&x[n],&y[n],&z[n],&x[n+1],&y[n+1],&z[n+1]);
		r[n]=r[n+1]=0;
		n+=2;
		for(i=0;i<n;++i)
			for(j=i;j<n;++j){
				res=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]))-r[i]-r[j];
				d[j][i]=d[i][j]=res>0?res:0;
			}
		for(k=0;k<n;++k)
			for(i=0;i<n;++i)
				for(j=0;j<n;++j)
					if(d[i][j]>d[i][k]+d[k][j])
						d[i][j]=d[i][k]+d[k][j];
		printf("Cheese %u: Travel time = %u sec\n",++T,unsigned(d[n-2][n-1]*10+0.5));
	}
	return 0;
}

