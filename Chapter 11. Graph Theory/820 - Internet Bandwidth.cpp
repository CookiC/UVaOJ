#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<cstdlib> 
#define INF 0x7FFFFFFF
#define maxn 1010
using namespace std;

struct Edge{
	int c,f;
	unsigned v,flip;
	Edge(unsigned v,int c,int f,unsigned flip):v(v),c(c),f(f),flip(flip){}
};

struct Dinic{
	unsigned s,t;									//Դ�㡢��� 
	bool b[maxn];									//BFSʹ�� 
	int a[maxn];									//a��ʾ�ɸĽ��� ������ָ����ɸĽ���
	unsigned p[maxn],cur[maxn],d[maxn];				//p[v]��ʾu��v�ķ���� ��v��u�ı� cur[u]��ʾi��ʼ 
	vector<Edge> G[maxn];							//������λ�� ��λ��ǰ����·������ 
	
	void init(unsigned n){
		for(int i=0;i<=n;++i)
			G[i].clear();
	}
	
	void AddEdge(unsigned u,unsigned v,int c){
		G[u].push_back(Edge(v,c,0,G[v].size()));
		G[v].push_back(Edge(u,c,0,G[u].size()-1));	//ʹ������ͼʱ��0��Ϊc���� 
	}
	
	bool BFS(){
		unsigned u,v;
		queue<unsigned> q;
		memset(b,0,sizeof(b));
		q.push(s);
		d[s]=0;
		b[s]=1;
		while(!q.empty()){
			u=q.front();
			q.pop();
			for(auto it=G[u].begin();it!=G[u].end();++it){
				Edge &e=*it;
				if(!b[e.v]&&e.c>e.f){
					b[e.v]=1;
					d[e.v]=d[u]+1;
					q.push(e.v);
				}
			}
		}
		return b[t];
	}
	
	int DFS(unsigned u,int a){
		if(u==t||a==0)
			return a;
		int flow=0,f;
		for(unsigned &i=cur[u];i<G[u].size();++i){
			Edge &e=G[u][i];
			if(d[u]+1==d[e.v]&&(f=DFS(e.v,min(a,e.c-e.f)))>0){
				a-=f;
				e.f+=f;
				G[e.v][e.flip].f-=f;
				flow+=f;
				if(!a) break;
			}
		} 
		return flow;
	}
	
	int Maxflow(unsigned s,unsigned t){
		int flow=0;
		this->s=s;
		this->t=t;
		while(BFS()){
			memset(cur,0,sizeof(cur));
			flow+=DFS(s,INF);
		}
		return flow;
	}
};

Dinic Dc;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	ios::sync_with_stdio(false);
	int i,w;
	unsigned T,n,s,t,m,u,v;
	for(T=1;cin>>n&&n;++T){
		Dc.init(n);
		cin>>s>>t>>m;
		for(i=0;i<m;++i){
			cin>>u>>v>>w;
			Dc.AddEdge(u,v,w);
		}
		cout<<"Network "<<T<<'\n';
		cout<<"The bandwidth is "<<Dc.Maxflow(s,t)<<".\n\n"; 
	}
	return 0;
}

