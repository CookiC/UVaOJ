#include<iostream>
#include<iomanip>
#include<queue>
#include<set>
#include<cstring>
#include<cstdlib>
#define N 4
#define M 6
#define maxw 100000
using namespace std;

struct State{
	unsigned d[5]={0};
	bool operator < (const State &b) const{
		return memcmp(d,b.d,sizeof(d))<0;
	}
};
const char dir[]="WNES";
const int dx[]={0,-1,0,1},dy[]={-1,0,1,0};
const unsigned bound[][M]={{3,2,2,2,2,6},
						   {1,0,0,0,0,4},
						   {1,0,0,0,0,4},
						   {9,8,8,8,8,12}};
char W[maxw],s[1000];
unsigned a[N][M],F[maxw];
set<State> dedup;

State Code(unsigned (*a)[M],unsigned z){
	int i,j;
	State res;
	for(i=0;i<N;++i)
		for(j=0;j<M;++j)
			res.d[i]|=a[i][j]<<j*4;
	res.d[4]=z;
	return res;
}

void Decode(State code,unsigned (*a)[M],unsigned &z){
	int i,j;
	for(i=0;i<N;++i)
		for(j=0;j<M;++j)
			a[i][j]=code.d[i]>>j*4&15;
	z=code.d[4];
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	int i,j,f,r;
	unsigned x,y;
	State code;
	while(cin>>y>>x&&y){
		for(i=0;i<N;++i)
			for(j=0;j<M;++j)
				cin>>a[i][j];
		
		queue<State> q;
		dedup.clear();
		code=Code(a,(x-1)*M+y-1);
		q.push(code);
		dedup.insert(code);
		r=1;
		for(f=0;!q.empty();++f){
			unsigned z;
			Decode(q.front(),a,z);
			q.pop();
			int ux=z/M;
			int uy=z%M;
//			cout<<setw(3)<<ux<<' '<<uy<<'\n';
//			Print();
			if(~a[ux][uy]&bound[ux][uy]){
				int k;
				for(k=0;!((~a[ux][uy]&bound[ux][uy])>>k&1);++k);
				F[r]=f;
				W[r]=dir[k];
				break;
			}
			for(i=0;i<4;++i){
				int vx=ux+dx[i];
				int vy=uy+dy[i];
				if(0<=vx&&vx<N&&0<=vy&&vy<M){
					bool pos=0;
					if(a[ux][uy]>>i&1){
						if(a[vx][vy]>>i&1)
							continue;
						a[ux][uy]^=1<<i;
						a[vx][vy]^=1<<(i+2)%4;
						a[vx][vy]|=1<<i;
						if(0<=vx+dx[i]&&vx+dx[i]<N&&0<=vy+dy[i]&&vy+dy[i]<M)
							a[vx+dx[i]][vy+dy[i]]|=1<<(i+2)%4;
						pos=1;
					}
					code=Code(a,vx*M+vy);
					if(dedup.find(code)==dedup.end()){
						q.push(code);
						dedup.insert(code);
						F[r]=f;
						W[r++]=dir[i];
					}
					if(pos){
						if(0<=vx+dx[i]&&vx+dx[i]<N&&0<=vy+dy[i]&&vy+dy[i]<M)
							a[vx+dx[i]][vy+dy[i]]^=1<<(i+2)%4;
						a[vx][vy]^=1<<i;
						a[vx][vy]|=1<<((i+2)%4);
						a[ux][uy]|=1<<i;
						
					}
				}
			}
		}
		j=0;
		for(i=r;i>0;i=F[i])
			s[j++]=W[i];
		for(i=j-1;i>=0;--i)
			cout<<s[i];
		cout<<'\n';
	}
	return 0;
}

