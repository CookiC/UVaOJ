#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define maxn 10010
using namespace std;

bool c[maxn][maxn];
unsigned n,m,k;
unsigned C[maxn];
vector<unsigned> G[maxn];

void DFS(unsigned u){
	int i;
	memset(c[u],0,sizeof(c[u]));
	for(auto it=G[u].begin();it!=G[u].end();++it){
		unsigned v=*it;
		if(C[v])
			c[u][C[v]]=1;
	}
	for(i=1;i<=k&&c[u][i];++i);
	C[u]=i;
	for(auto it=G[u].begin();it!=G[u].end();++it){
		unsigned v=*it;
		if(!C[v])
			DFS(v);
	}
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);

	ios::sync_with_stdio(false);

    int i,j,l;
	unsigned u,v;
	while(cin>>n>>m){
		memset(C,0,sizeof(C));
		for(i=1;i<=n;++i)
			G[i].clear();
		for(i=0;i<m;++i){
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		k=0;
		for(i=1;i<=n;++i)
			if(G[i].size()>k)
				k=G[i].size();
		if(k%2==0)
			++k;
		DFS(1);
        cout<<k<<'\n';
        for(i=1;i<=n;++i)
            cout<<(unsigned)C[i]<<'\n';
        cout<<'\n';
	}
	return 0;
}

