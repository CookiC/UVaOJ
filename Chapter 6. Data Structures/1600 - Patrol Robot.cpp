#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int T;
unsigned i,j,n,m,k;
unsigned obs[30][30],reach[30][30];
int way[30][30],incx[4]={1,0,0,-1},incy[4]={0,1,-1,0};
queue<int> q;

void Initial(){
	memset(way,0xFF,sizeof(way));
	memset(reach,0xFF,sizeof(reach));
	way[0][0]=0;
	reach[0][0]=0;
	while(!q.empty())
	  q.pop();
}

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  scanf("%d",&T);
  while(T--){
  	scanf("%u%u%u",&n,&m,&k);
  	for(i=0;i<n;++i)
  	  for(j=0;j<m;++j)
  	    scanf("%u",&obs[i][j]);
  	Initial();
  	
  	q.push(0);
  	while(!q.empty()){
  		int ux=q.front()/m;
  		int uy=q.front()%m;
			q.pop();
  		if(ux==n-1&&uy==m-1)
  		  break;
  		if(reach[ux][uy]<=k)
  		  for(i=0;i<4;++i){
  			  int vx=ux+incx[i];
  			  int vy=uy+incy[i];
//  			  printf("(%d,%d)\n",vx,vy);
  			  if(0<=vx&&vx<n&&0<=vy&&vy<m)
  			  	if(way[vx][vy]<0){
  			  		if(obs[vx][vy])
  			  		  reach[vx][vy]=reach[ux][uy]+1;
							else
							  reach[vx][vy]=0;
							if(reach[vx][vy]<=k){
  			  	    way[vx][vy]=way[ux][uy]+1;
  			        q.push(vx*m+vy);
  			      }
  			    }
  			  	else if(reach[vx][vy]>reach[ux][uy]+1){
  			  	  reach[vx][vy]=reach[ux][uy]+1;
  			  	  q.push(vx*m+vy);
  			  	}
  			}
		}
/*  
		printf("Obs:\n");
		for(i=0;i<n;++i){
		  for(j=0;j<m;++j)
		    printf("%3d",obs[i][j]);
		  printf("\n");
		}
		
		printf("Reach:\n");
		for(i=0;i<n;++i){
		  for(j=0;j<m;++j)
		    printf("%3d",reach[i][j]);
		  printf("\n");
		}
		
		printf("Way:\n");
		for(i=0;i<n;++i){
		  for(j=0;j<m;++j)
		    printf("%3d",way[i][j]);
		  printf("\n");
		}
*/
		printf("%d\n",way[n-1][m-1]);
	}
  return 0;
}

