#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int reach[9][9],incx[8]={-2,-2,-1,-1,1,1,2,2},incy[8]={1,-1,2,-2,2,-2,1,-1};
int bx,by,ex,ey;
queue<unsigned> q;

void Initial(){
	unsigned i;
	memset(reach,0XFF,sizeof(reach));
	while(!q.empty())
	  q.pop();
}

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  char bc,ec;
  while(scanf("%c%d %c%d\n",&bc,&bx,&ec,&ex)!=EOF){
    unsigned i,j;
		Initial();
    by=bc-'a'+1;
    ey=ec-'a'+1;
    reach[bx][by]=0;
    q.push(bx*10+by);
    while(!q.empty()){
    	int ux=q.front()/10;
    	int uy=q.front()%10;
    	q.pop();
    	if(ux==ex&&uy==ey)
    	  break;
      for(i=0;i<8;++i){
      	int vx=ux+incx[i];
      	int vy=uy+incy[i];
      	if(1<=vx&&vx<=8&&1<=vy&&vy<=8&&reach[vx][vy]<0){
      		reach[vx][vy]=reach[ux][uy]+1;
      		q.push(vx*10+vy);
		  	}
		  }
	  printf("To get from %c%d to %c%d takes %d knight moves.\n",bc,bx,ec,ex,reach[ex][ey]);
	}
  return 0;
}

