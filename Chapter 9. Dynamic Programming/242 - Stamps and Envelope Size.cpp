#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp(const unsigned *a,const unsigned *b){
	if(a[0]==b[0]){
		int i;
		for(i=a[0];i>0&&a[i]==b[i];--i);
		return a[i]<b[i];
	}
	return a[0]<b[0];
}

bool dp[1010],used[1010];
int i,j,k,l;
unsigned S,N,maxd,len,maxl;
unsigned *de[15],date[15][15],*curd,*p;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	while(scanf("%u",&S)!=EOF&&S){
		scanf("%u",&N);
		for(i=0;i<N;++i){
			de[i]=date[i];
			scanf("%u",&date[i][0]);
			for(j=1;j<=date[i][0];++j)
				scanf("%u",&date[i][j]);
		}
		sort(de,de+N,cmp);
		
		maxl=0;
		p=de[0];
		for(i=0;i<N;++i){
			memset(used,0,sizeof(used));
			memset(dp,0,sizeof(dp));
			curd=de[i];
			maxd=0;
			dp[0]=1;
			
			for(j=0;j<S;++j)
				for(k=maxd;k>=0;--k)
					if(dp[k]&&!used[k]){
						for(l=1;l<=curd[0];++l){
							dp[k+curd[l]]=1;
							if(k+curd[l]>maxd)
								maxd=k+curd[l];
						}
						used[k]=1;
					}
			
			for(j=1;j<=maxd&&dp[j];++j);
			len=j-1;
			if(len>maxl){
				maxl=len;
				p=curd;
			}
		}
		
		printf("max coverage =%4u :",maxl);
		for(i=1;i<=p[0];++i)
				printf("%3u",p[i]);
		printf("\n");
	}
	return 0;
}

