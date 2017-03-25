#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

int n,m,s,t;
int dup[524288];
unsigned data[524288];
queue<unsigned> q;
vector<unsigned> G[16];

unsigned Code(bool *s,unsigned p){
	unsigned sum=0;
	for(int i=1;i<=n;++i)
		sum|=s[i]<<i-1;
	sum|=p<<n;
	return sum;
}

void Decode(unsigned code,bool *s,unsigned &p){
	memset(s,0,sizeof(s));
	for(int i=1;i<=n;++i){
		s[i]=code&1;
		code>>=1;
	}
	p=code;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);

	bool us[16],vs[16];
	int i,j;
	unsigned u,v,k,T;
	scanf("%d",&T);
	for(k=1;k<=T;++k){
		memset(us,0,sizeof(us));
		for(i=1;i<=n;++i)
			G[i].clear();
		scanf("%d%d%d%d",&n,&m,&s,&t);
		us[s]=1;
		for(i=0;i<m;++i){
			scanf("%d",&j);
			us[j]=1;
		}
		for(i=0;i<n-1;++i){
			scanf("%u%u",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		memset(dup,0,sizeof(dup));
		while(!q.empty())
			q.pop();
		unsigned uz=Code(us,s);
		q.push(uz);
		dup[uz]=-1;
		while(!q.empty()){
			unsigned up,vp,vz;
			uz=q.front();
			q.pop();
			Decode(uz,us,up);
			if(up==t)
				break;
			for(u=1;u<=n;++u)
				if(us[u]){
					for(j=0;j<G[u].size();++j){
						v=G[u][j];
						if(!us[v]){
							memcpy(vs,us,sizeof(us));
							vs[v]=1;vs[u]=0;
							if(up==u)	vp=v;
							else		vp=up;
							vz=Code(vs,vp);
							if(!dup[vz]){
								dup[vz]=uz;
								data[vz]=u*100+v;
								q.push(vz);
							}
						}
					}
				}
		} 
		printf("Case %u: ",k); 
		if(q.empty())
			printf("-1");
		else{
			int f=uz;
			unsigned cnt=0,way[100];
			for(cnt=0;f>0;++cnt){
				way[cnt]=data[f];
				f=dup[f];
			}
			printf("%u\n",--cnt);
			for(i=cnt-1;i>=0;--i)
				printf("%u %u\n",way[i]/100,way[i]%100);	
		}
		printf("\n");
	}
	return 0;
}

