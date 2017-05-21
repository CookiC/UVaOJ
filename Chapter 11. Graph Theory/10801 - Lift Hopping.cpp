//#include"stdafx.h"
#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<vector>
#include<sstream>
//#pragma warning(disable : 4996)
#define maxn 500
#define topn 100
#define INF 0x7FFFFFFF
using namespace std;

struct Edge{
	int v,w;
	Edge(int v,int w):v(v),w(w){}
};
int N,K;
int d[maxn];
bool inq[maxn];
vector<Edge> G[maxn];

void SPFA(int s){
	queue<int> q;
	memset(inq,0,sizeof(inq));
	memset(d,0xFF,sizeof(int)*N*topn);
	for(int i=0;i<N*topn;++i)
		d[i]=INF;
	d[s]=0;
	inq[s]=1;
	q.push(s);
	
	int u;
	while(!q.empty()){
		u=q.front();
		q.pop();
		inq[u]=0;
		
		for(auto e=G[u].begin();e!=G[u].end();++e)
			if(d[e->v]>d[u]+e->w){
				d[e->v]=d[u]+e->w;
				if(!inq[e->v]){
					q.push(e->v);
					inq[e->v]=1;
				}
			}
	}
}

int main(){
	ios::sync_with_stdio(false);
	
	int i,j,k,v,u;
	int t[10];
	string str;
	stringstream sio;
	while(cin>>N>>K){
		for (i = 0; i < N; ++i)
			for (j = 0; j < topn; ++j)
				G[i*topn+j].clear();
		for(i=0;i<N;++i){
			cin>>t[i];
			for(j=0;j<N;++j)
				if(i!=j)
					for(k=1;k<topn;++k){
						u=topn*i+k;
						v=topn*j+k;
						G[u].push_back(Edge(v,60));
					}
		}
		
		getline(cin,str);
		for(i=0;i<N;++i){
			getline(cin,str);
			sio.clear();
			sio<<str;
			sio>>u;
			u=topn*i+u;
			while(sio>>v){
				v=topn*i+v;
				int w=(v-u)*t[i];
				G[u].push_back(Edge(v,w));
				G[v].push_back(Edge(u,w));
				u=v;
			}
		}
		
		int minc=INF;
		for(i=0;i<N;++i){
			u=topn*i;
			SPFA(u);
			for (j = 0; j<N;++j)
				if(minc>d[j*topn+K])
					minc=d[j*topn+K];
		}
		if (minc < INF)
			cout << minc << endl;
		else
			cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}

