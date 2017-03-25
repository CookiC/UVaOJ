#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
bool b[20][20];
int a[20][20],ans[100];
unsigned R,C,len,maxl;
unsigned p[100],num[100];

unsigned find(unsigned x){
	return p[x]==x?x:p[x]=find(p[x]);
}

bool cmp(unsigned x,unsigned y){
	return	a[x/(C+2)][x%(C+2)]>a[y/(C+2)][y%(C+2)];
}

void DFS(unsigned ux,unsigned uy,unsigned l){
	static int stk[100];
	int i,j;
	unsigned vx,vy;
	unsigned q[4];
	stk[l-1]=a[ux][uy];
	for(i=0;i<4;++i){
		vx=ux+dx[i];
		vy=uy+dy[i];
		if(a[vx][vy]>=0&&!b[vx][vy]){
			b[vx][vy]=1;
			DFS(vx,vy,l+1);
			b[vx][vy]=0;
		}
	}
	
	if(l>len||l==len&&memcmp(stk,ans,sizeof(int)*len)>0){
		len=l;
		memcpy(ans,stk,sizeof(int)*len);
	}
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	int i,j,k,z;
	char s[20][20];
	int ns[100][40];
	unsigned q[100];
	while(scanf("%u%u",&R,&C)!=EOF&&R){
		for(i=0;i<R;++i)
			scanf("%s",s[i]);
		memset(a,-1,sizeof(a));
		for(i=0;i<R;++i)
			for(j=0;j<C;++j)
				if(s[i][j]!='#')
					a[i+1][j+1]=s[i][j]-'0';
		
		k=0;
		for(i=1;i<=R;++i)
			for(j=1;j<=C;++j){
				z=i*(C+2)+j;
				p[z]=z;
				num[z]=1;
				ns[z][0]=a[i][j];
				q[k++]=z;
			}
		
		sort(q,q+k,cmp);
		for(i=1;i<=R;++i)
			for(j=1;j<=C;++j)
				for(k=0;k<4;++k)
					if(a[i][j]>=0&&a[i+dx[k]][j+dy[k]]>=0){
						unsigned zu=i*(C+2)+j;
						unsigned zv=(i+dx[k])*(C+2)+j+dy[k];
						unsigned x=find(zu);
						unsigned y=find(zv);
						if(x!=y){
							int c[100],l=0,m=0;
							while(l<num[x]&&m<num[y]){
								while(l<num[x]&&(m>=num[y]||ns[x][l]>=ns[y][m])){
									c[l+m]=ns[x][l];
									++l;
								}
								while(m<num[y]&&(l>=num[x]||ns[x][l]<ns[y][m])){
									c[l+m]=ns[y][m];
									++m;
								}
							}
							num[x]+=num[y];
							for(l=0;l<num[x];++l){
								ns[x][l]=c[l];
							}
							p[y]=x;
						}
					}

		len=0;
		memset(ans,0,sizeof(ans));
		for(k=0;k<=R*C;++k){
			i=q[k]/(C+2);
			j=q[k]%(C+2);
			if(a[i][j]>=0){
				memset(b,0,sizeof(b));
				z=find(i*(C+2)+j);
				maxl=num[z];
				b[i][j]=1;
				if(maxl>len||maxl==len&&a[i][j]>=ans[0]&&memcmp(ns[z],ans,len*sizeof(int))>0)
					DFS(i,j,1);
			}
			else
				break;
		}
		for(i=0;i<len;++i)
			printf("%u",ans[i]);
		printf("\n");
	}
	return 0;
}

