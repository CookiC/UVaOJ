#include<cstdio>
#include<cstring>

bool b[11][11];
unsigned n,m;

bool DFS(bool ub[][11],unsigned deep){
	int i,j,k,l;
	bool vb[11][11];
	unsigned cnt[11][11];
	memset(cnt,0,sizeof(cnt)); 
	for(i=0;i<n;++i)
		for(j=0;j<m;++j)
			if(ub[i][j]){
				for(k=0;k<m;++k)	++cnt[i][k];
				for(k=0;k<n;++k)	++cnt[k][j];
				for(k=1;i+k<n&&j+k<m;++k)	++cnt[i+k][j+k];
				for(k=1;i-k>=0&&j-k>=0;++k)	++cnt[i-k][j-k];
				for(k=1;i+k<n&&j-k>=0;++k)	++cnt[i+k][j-k];
				for(k=1;i-k>=0&&j+k<m;++k)	++cnt[i-k][j+k];
				--cnt[i][j];
			}
	if(!deep){
		unsigned cntn=0,maxcnt=0,mi,mj;
		for(i=0;i<n;++i)
			for(j=0;j<m;++j){
				if(ub[i][j])
					++cntn;
				if(cnt[i][j]>maxcnt){
					maxcnt=cnt[i][j];
					mi=i;
					mj=j;
				}
			}
		if(maxcnt==cntn){
//			printf("(%u,%u)\n",mi,mj);
			return true;
		}
		return false;
	}
	for(i=0;i<n;++i)
		for(j=0;j<m;++j){
			if(cnt[i][j]>1){
				memcpy(vb,ub,121*sizeof(bool));
				for(k=0;k<m;++k)	vb[i][k]=0;
				for(k=0;k<n;++k)	vb[k][j]=0;
				for(k=1;i+k<n&&j+k<m;++k)	vb[i+k][j+k]=0;
				for(k=1;i-k>=0&&j-k>=0;++k)	vb[i-k][j-k]=0;
				for(k=1;i+k<n&&j-k>=0;++k)	vb[i+k][j-k]=0;
				for(k=1;i-k>=0&&j+k<m;++k)	vb[i-k][j+k]=0;
				if(DFS(vb,deep-1)){
//					printf("(%u,%u)\n",i,j);
					return true;
				}
			}}
	return false;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	int i,j;
	for(unsigned T=1;scanf("%u%u",&n,&m)!=EOF&&n;++T){
		memset(b,0,sizeof(b));
		for(i=0;i<n;++i){
			getchar();
			for(j=0;j<m;++j){
				char c;
				c=getchar();
				if(c=='X')
					b[i][j]=1;
			}
		}
		
		for(i=0;!DFS(b,i);++i);
		printf("Case %u: %u\n",T,i+1);
	}
	return 0;
}

