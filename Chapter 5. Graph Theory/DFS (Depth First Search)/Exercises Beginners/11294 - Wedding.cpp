//Author:CookiC
#include"stdafx.h"
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<cctype>
#define maxn 40
#pragma warning(disable : 4996)
using namespace std;

class TwoSAT{
private:
	const static int maxm=maxn*2;
	
	int S[maxm],c;
	vector<int> G[maxm];
	
	bool DFS(int u){
		if(vis[u^1])
			return false;
		if(vis[u])
			return true;
		vis[u]=1;
		S[c++]=u;
		for(auto it=G[u].begin();it!=G[u].end();++it){
			int v=*it;
			if(!DFS(v))
				return false;
		}
		return true;
	}
	
public:
	int N;
	bool vis[maxm];
	
	void Clear(){
		for(int i=2;i<N*2;++i)
			G[i].clear();
		memset(vis,0,sizeof(bool)*N*2);
	}
	
	void AddClause(int x,int xv,int y,int yv){
		x=x*2+xv;
		y=y*2+yv;
		G[x^1].push_back(y);
		G[y^1].push_back(x);
	}
	
	bool Solve(){
		int i;
		for(i=2;i<N*2;i+=2)
			if(!vis[i]&&!vis[i+1]){
				c=0;
				if(!DFS(i)){
					while(c>0)
						vis[S[--c]]=0;
					if(!DFS(i+1))
						return false;
				}
			}
		return true;
	}
};

int Code(string &s){
	int code=0;
	for(int i=s.size()-2;i>=0;--i)
		code=code*10+s[i]-'0';
	return code;
}

TwoSAT sat;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int n,m,i,xc,yc,xv,yv;
	bool b;
	string x,y;
	while(cin>>n>>m&&n){
		b=1;
		sat.N=n;
		sat.Clear();
		for(i=0;i<m;++i){
			cin>>x>>y;
			if(*x.rend()=='h')
				xv=0;
			else
				xv=1;
			if(*y.rend()=='h')
				yv=0;
			else
				yv=1;
			xc=Code(x);
			yc=Code(y);
			sat.AddClause(xc,xv,yc,yv);
			sat.AddClause(xc,xv^1,yc,yv^1);
			if((xc&1)==(yc&1))
				b=0;
		}
		if(b)
			for(i=1;i<n;++i)
				cout<<i<<"h ";
		else if(sat.Solve()){
			for(i=1;i<n;++i)
				if(sat.vis[i*2])
					cout<<i<<"h ";
				else
					cout<<i<<"w ";
		}
		else
			cout<<"bad luck";
		cout<<endl;
	}
	return 0;
}

