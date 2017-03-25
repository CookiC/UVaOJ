#include<cstdio>
#include<cstring>
#define Mod 10001

unsigned Code(bool s[5][5]){
	int i,j,k=0;
	unsigned res=0;
	for(i=0;i<5;++i)
		for(j=0;j<=i;++j)
			res|=s[i][j]<<k++;
	return res;
}

void Decode(unsigned code,bool s[5][5]){
	int i,j,k=0,cnt=0;
	memset(s,0,sizeof(s));
	for(i=0;i<5;++i)
		for(j=0;j<=i;++j){
			s[i][j]=(code>>k++)&1;
			if(s[i][j])
				++cnt;
		}
}

const int dx[]={-1,-1,0,0,1,1},dy[]={-1,0,-1,1,0,1};
bool dup[65536];
int fa[65536];
unsigned au[65536],av[65536],q[Mod];

int BFS(unsigned code0){
	unsigned f=0,r=0;
	bool us[5][5],vs[5][5];
	int i,j,ux,uy,uc;
	
	memset(fa,0,sizeof(fa));
	memset(dup,0,sizeof(dup));
	fa[code0]=-1;
	q[r++]=code0;
	dup[code0]=1;
	while(f<r){
		uc=q[f++%Mod];
		if(!(code0&uc))
			return uc;
		Decode(uc,us);
		for(ux=0;ux<5;++ux)
			for(uy=0;uy<=ux;++uy)
				if(us[ux][uy]){
					for(i=0;i<6;++i){
						int vx=ux+dx[i];
						int vy=uy+dy[i];
						if(0<=vx&&vx<5&&0<=vy&&vy<=vx&&us[vx][vy]){
							memcpy(vs,us,sizeof(us));
							while(0<=vx&&vx<5&&0<=vy&&vy<=vx&&us[vx][vy]){
								vs[vx][vy]=0;
								vx+=dx[i];
								vy+=dy[i];
							}
							if(0<=vx&&vx<5&&0<=vy&&vy<=vx){
								vs[vx][vy]=1;
								vs[ux][uy]=0;
								int vc=Code(vs);
								if(!dup[vc]){
									fa[vc]=uc;
									au[vc]=ux*(ux+1)/2+uy;
									av[vc]=vx*(vx+1)/2+vy;
									q[r++%Mod]=vc;
									dup[vc]=1;
								}
							}
						}
					}
				}
	}
	return 0;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);

	bool s0[5][5];
	int T,n,i,j;
	int way[16];
	unsigned cnt;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=0;i<5;++i)
			for(j=0;j<=i;++j)
				if(--n)
					s0[i][j]=1;
				else
					s0[i][j]=0;
		
		n=BFS(Code(s0));
		
		if(n){
			cnt=0;
			for(i=n;i>=0;i=fa[i])
				way[cnt++]=i;
			printf("%u\n",cnt-1);
			for(i=cnt-2;i>0;--i)
				printf("%u %u ",au[way[i]]+1,av[way[i]]+1);
			printf("%u %u\n",au[way[0]]+1,av[way[0]]+1);
		}
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}

