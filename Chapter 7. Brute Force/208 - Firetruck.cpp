#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

unsigned k,u,v,n,cnt,way[25],uFind[25];
bool G[25][25],used[25];

void DFS(unsigned u,unsigned deep){
	unsigned i;
	if(u==k){
		printf("1");
		for(i=1;i<deep;++i)
		  printf(" %u",way[i]);
		printf("\n");
		++cnt;
		return;
	}
//	printf("deep:%u u:%u\n",deep,u);
	for(i=1;i<=n;++i)
	  if(G[u][i]&&!used[i]){
	  	used[i]=true;
	  	way[deep]=i;
	  	DFS(i,deep+1);
	  	used[i]=false;
		}
}

inline unsigned find(unsigned x){
	return uFind[x]==x?x:uFind[x]=find(uFind[x]);
}

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  for(unsigned T=1;scanf("%u",&k)!=EOF;++T){
  	memset(G,0,sizeof(G));
  	memset(used,0,sizeof(used));
  	memset(way,0,sizeof(way));
  	cnt=0;
  	for(unsigned i=0;i<25;++i)
  	  uFind[i]=i;
  	
  	n=0;
  	while(scanf("%u%u",&u,&v)!=EOF&&u){
  		G[u][v]=G[v][u]=1;
  		n=max(n,max(u,v));
  		unsigned x=find(u);
  		unsigned y=find(v);
  		uFind[x]=y;
  	}
  	printf("CASE %u:\n",T);
  	if(find(1)==find(k)){
    	way[0]=1;
    	used[1]=true;
  	  DFS(1,1);
  	}
  	printf("There are %u routes from the firestation to streetcorner %u.\n",cnt,k);
	};
  return 0;
}

