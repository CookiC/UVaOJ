#include<cstdio>
#include<vector>
using namespace std;

unsigned n;
unsigned b[1010],d[1010],di[1010],deep[1010],fa[1010];
vector<unsigned> son[1010];

void DFS(unsigned fa){
	unsigned i,j,k;
	for(i=1;i<son[fa].size();++i){
	  if(son[fa][i-1]>son[fa][i]){
	  	k=son[fa][i-1];
	  	j=i;
	    while(i<son[fa].size()){
	    	son[k].push_back(son[fa][i]);
	    	++i;
			}
			son[fa].resize(j);
		}
		DFS(son[fa][i-1]);
	}
};

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  unsigned i,j;
  while(scanf("%u",&n)!=EOF){
  	for(i=0;i<=n;++i)
  	  son[i].clear();
  	for(i=0;i<n;++i)
  	  scanf("%u",&b[i]);
  	for(i=0;i<n;++i){
  	  scanf("%u",&d[i]);
  	  di[d[i]]=i;
  	}
  	
  	j=2;
  	deep[b[0]]=1;
  	for(i=1;i<n;++i){
  		if(di[b[i-1]]>di[b[i]])
  		  ++j;
  		deep[b[i]]=j;
		}
  	fa[d[0]]=0;
  	i=0;
		unsigned root=d[0];
		while(i<n){
  	  if(deep[d[i]]==deep[root]+1){
  	    son[root].push_back(d[i]);
  	    fa[d[i]]=root;
  	    root=d[i];
  	    ++i;
  	  }
  	  else
  	  	while(deep[d[i]]<=deep[root])
  	  	  root=fa[root];
  	}
  	DFS(d[0]);
  	
  	for(i=1;i<=n;++i){
  		printf("%u:",i);
  		for(j=0;j<son[i].size();++j)
  		  printf(" %u",son[i][j]);
  		printf("\n");
		}
	};
  return 0;
}

