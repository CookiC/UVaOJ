#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int i,j,k,n;
unsigned len[13];
vector<bool> G[13];
char P[13][150][250];
char (*p)[250];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);

//0是逆时针	1是顺时针 
	G[0].push_back(1);
	for(i=1;i<13;++i){
		G[i]=G[i-1];
		G[i].push_back(1);
		for(j=0;j<G[i-1].size();++j)
			G[i].push_back(!G[i-1][G[i-1].size()-j-1]);
	}

	memset(P,0,sizeof(P));
	for(i=0;i<13;++i){
		int x=0,y=1;
		int minx=0,miny=0,maxx=0;
		bool r=1,u=1;
		for(j=0;j<G[i].size();++j){
			if(y<miny)	miny=y;
			if(G[i][j]^r)	{--x;u=0;}
			else			{++x;u=1;}
			if(++j>=G[i].size())	break;
			if(x<minx)	minx=x;
			if(x>maxx)	maxx=x;
			if(G[i][j]^u)	{y+=2;r=1;}
			else			{y-=2;r=0;}
		}
		x=-minx;y=1-miny;
		maxx-=minx;len[i]=maxx;
		p=P[i]; 
		p[x][y-1]='_';
		k=y-2;
		while(k>=0&&!p[x][k])
			p[x][k--]=' ';
		r=1;
		for(j=0;j<G[i].size();++j){
			if(G[i][j]^r){
				p[x-1][y]='|';
				k=y-1;
				while(k>=0&&!p[x-1][k])
					p[x-1][k--]=' ';
				--x;u=0;
			}
			else{
				p[x][y]='|';
				++x;u=1;
			}
			if(++j>=G[i].size())	break;
			if(G[i][j]^u){
				p[x][y+1]='_';
				k=y;
				while(k>=0&&!p[x][k])
					p[x][k--]=' ';
				y+=2;r=1;
			}
			else{
				p[x][y-1]='_';
				k=y-2;
				while(k>=0&&!p[x][k])
					p[x][k--]=' ';
				y-=2;r=0;
			}
		}
	}
	
	while(scanf("%d",&n)!=EOF&&n){
		p=P[n-1];
		for(i=len[n-1];i>=0;--i)
			printf("%s\n",p[i]);
		printf("^\n");
	}
	return 0;
}

