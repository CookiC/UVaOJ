#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
using namespace std;

int T;
bool G[120][120],visit[120][120];
unsigned n,k,i,cnt;
unsigned way[25],dis[]={0,1,2,4,6,9,12,16,20,25,30,36,42,49,56,64,72,81,90,100,110};
int dx[]={0,-1,0,1},dy[]={1,0,-1,0};
char dir[]="senw";
set<string> s;

void DFS(int ux,int uy,unsigned ud,unsigned len){
	unsigned i;
	if(len==0){
	  if(ux==60&&uy==60){
	  	string str;
	  	str.resize(n);
		  for(i=1;i<=n;++i)
		    str[i-1]=dir[way[i]];
		  s.insert(str);
		  ++cnt;
	  }
	  return;
  }
	unsigned vd[2];
	vd[0]=(ud+1)%4;
	vd[1]=(ud+3)%4;
	for(i=0;i<2;++i){
	  int j=dx[vd[i]];
	  int k=dy[vd[i]];
		int vx=ux+j*len;
		int vy=uy+k*len;
		unsigned dvx=abs(vx-60);
		unsigned dvy=abs(vy-60);
		if(dvx<=dis[len]&&dvy<=dis[len]){
			unsigned x=ux,y=uy;
			while(!(x==vx&&y==vy)&&!G[x][y]){
				x+=j;
				y+=k;
			}
			if(!G[x][y]&&!visit[x][y]){
				visit[x][y]=true;
				way[len]=vd[i];
	      DFS(vx,vy,vd[i],len-1);
	      visit[x][y]=false;
	    }
	  }
  }
}

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  scanf("%d",&T);
  while(T--){
  	memset(way,0,sizeof(way));
  	memset(G,0,sizeof(G));
  	memset(visit,0,sizeof(visit));
  	
  	cnt=0;
  	s.clear();
  	
  	scanf("%u%u",&n,&k);
  	for(i=0;i<k;++i){
  		int x,y;
  		scanf("%d%d",&x,&y);
  		x+=60;
  		y+=60;
  		if(0<=x&&x<120&&0<=y&&y<120)
        G[x][y]=true;
		}
		
		DFS(60,60,0,n);
		DFS(60,60,1,n);
		for(auto it=s.begin();it!=s.end();++it)
			cout<<*it<<endl;
		printf("Found %u golygon(s).\n\n",cnt);
	}
  return 0;
}

