#include<cstdio>

int i,j,T=0;
unsigned n;
double Max;
double a[16386][8];
unsigned order[16386];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	while(scanf("%u",&n)!=EOF&&n){
		for(i=1;i<=n;++i){
			scanf("%lf%lf%lf",&a[i][0],&a[i][1],&a[i][2]);
			a[i][3]=a[i][0]+a[i][1];
			a[i][4]=a[i][0]+a[i][2];
			a[i][5]=a[i][1]+a[i][2];
			a[i][6]=a[i][0]+a[i][1]+a[i][2];
			a[i][7]=0;
		}
		for(i=0;i<n;++i)
			scanf("%u",&order[i]);
		Max=a[order[0]][6];
		
		for(i=1;i<n;++i){
			int cur=order[i];
			double t=-1;
			if(cur>order[i-1]){
				for(j=0;j<8;++j)
					if(t<a[cur][j]&&a[cur][j]<Max+1e-6)
						t=a[cur][j];
			}
			else
				for(j=0;j<8;++j)
					if(t<a[cur][j]&&a[cur][j]<Max)
						t=a[cur][j];
			Max=t;
			if(t<0)
				break;
		}
		
		printf("Case %u: ",++T);
		if(Max<0)
			printf("No solution\n");
		else
			printf("%.2lf\n",Max);
	}
	return 0;
}

