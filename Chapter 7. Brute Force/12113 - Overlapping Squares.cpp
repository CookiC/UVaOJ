#include<cstdio>
#include<cstring>
#include<iostream>
#include<set>
#include<ctime>
using namespace std;

struct State{
	unsigned G[4][4];
	State(unsigned *a){
		memcpy(G,a,16*sizeof(unsigned));
	}
	State(const void *a){
		memcpy(G,a,16*sizeof(unsigned));
	}

	bool operator < (const State b)const{
		if(memcmp(this,&b,sizeof(State))<0)
		  return true;
		return false;
	}
};

int dest[4][4];
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
char board[5][12];
set<State> st;

void Fill(int ux,int uy,unsigned num){
	const static int dbx[]={0,-1,0,0},dby[]={0,0,1,-1};
	int ubx=ux+1,uby=uy*2+1;
	unsigned i;
	dest[ux][uy]=num;
	for(i=0;i<4;++i){
		int vx=ux+dx[i];
	  int vy=uy+dy[i];
		if(0<=vx&&vx<4&&0<=vy&&vy<4&&dest[vx][vy]<0){
			unsigned vbx=ubx+dbx[i];
			unsigned vby=uby+dby[i];
			if(board[vbx][vby]==' ')
				Fill(vx,vy,num);
		}
	}
}

void Transform(int ux,int uy,unsigned num,const unsigned ust[][4],int vst[][4]){
	vst[ux][uy]=num;
	for(unsigned i=0;i<4;++i){
		int vx=ux+dx[i];
		int vy=uy+dy[i];
		if(0<=vx&&vx<4&&0<=vy&&vy<4&&
		   vst[vx][vy]<0&&ust[ux][uy]==ust[vx][vy])
		  Transform(vx,vy,num,ust,vst);
	}
}

void Save(const unsigned ust[4][4]){
	unsigned i,j,num=0;
	int vst[4][4];
	memset(vst,0xFF,sizeof(vst));
	for(i=0;i<4;++i)
	  for(j=0;j<4;++j)
	  	if(ust[i][j]==0)
	  	  vst[i][j]=0;
	    else if(vst[i][j]<0)
	      Transform(i,j,++num,ust,vst);
  st.insert(State(vst));
}

void DFS(unsigned deep,const unsigned ust[4][4]){
	
	if(deep>6)
		return;
	unsigned i,j,h,l;
	unsigned vst[4][4];
	memcpy(vst,ust,16*sizeof(unsigned));
	for(i=0;i<3;++i)
	  for(j=0;j<3;++j){
	  	for(h=0;h<2;++h)
	  	  for(l=0;l<2;++l)
	  	    vst[i+h][j+l]=deep;
			Save(vst);
	  	DFS(deep+1,vst);
	  	for(h=0;h<2;++h)
	  	  for(l=0;l<2;++l)
	  	    vst[i+h][j+l]=ust[i+h][j+l];
		}
}

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  char c;
  unsigned i,j,n;
  unsigned state[4][4];
  memset(state,0,sizeof(state));
  DFS(1,state);
	for(unsigned T=1;cin.getline(board[0],12)&&board[0][0]!='0';++T){
    memset(dest,0xFF,sizeof(dest));
    
    board[0][9]='\0';
		for(i=1;i<5;++i){
      cin.getline(board[i],12);
      board[i][9]='\0';
    }
    
    for(i=0;i<4;++i){
      if(dest[i][0]<0&&board[i+1][0]==' ')
        Fill(i,0,0);
			if(dest[i][3]<0&&board[i+1][8]==' ')
        Fill(i,3,0);
      if(dest[0][i]<0&&board[0][i*2+1]==' ')
        Fill(0,i,0);
      if(dest[3][i]<0&&board[4][i*2+1]==' ')
        Fill(3,i,0);
    }
    
		n=0;
    for(i=0;i<4;++i){
      for(j=0;j<4;++j){
        if(dest[i][j]<0)
          Fill(i,j,++n);
//        printf("%3u",dest[i][j]);
      }
//      printf("\n");
		}
    
    printf("Case %u: ",T);
    if(st.find(State(dest))!=st.end())
		  printf("Yes\n");
		else
		  printf("No\n");
  }
  return 0;
}

