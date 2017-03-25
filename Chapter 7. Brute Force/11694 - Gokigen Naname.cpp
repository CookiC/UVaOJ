#include<iostream>
#include<cstring>
using namespace std;

const char dx[][2]={{0,1},{1,0}},dy[][2]={{0,1},{0,1}};
int N;
unsigned n;
bool b[10][10];
int a[10][10];
unsigned P[100],cnt[10][10];

unsigned find(unsigned x){
	return P[x]==x?x:find(P[x]);
}

bool DFS(unsigned z){
	if(z==n*n){
		if(a[n][n]<0||a[n][n]==cnt[n][n])
			return true;
		return false; 
	}
	int i;
	int x=z/n;
	int y=z%n;
	for(i=0;i<2;++i){
		b[x][y]=i;
		int vx1=x+dx[i][0];
		int vy1=y+dy[i][0];
		unsigned z1=vx1*(n+1)+vy1;
		int vx2=x+dx[i][1];
		int vy2=y+dy[i][1];
		unsigned z2=vx2*(n+1)+vy2;
		int j=find(z1);
		int k=find(z2);
		++cnt[vx1][vy1];
		++cnt[vx2][vy2];
		if(j!=k&&(a[x][y]<0||a[x][y]==cnt[x][y])&&
		(y<n-1||a[x][y+1]<0||a[x][y+1]==cnt[x][y+1])&&
		(x<n-1||a[x+1][y]<0||a[x+1][y]==cnt[x+1][y])){
			P[j]=k;
			if(DFS(z+1))
				return true;
			P[j]=j;
		}
		--cnt[vx1][vy1];
		--cnt[vx2][vy2];
	}
	return false;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	char s[10][10];
	cin>>N;
	while(N--){
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(i=0;i<=n;++i)
			cin>>s[i];
		for(i=0;i<=n;++i){
			for(j=0;j<=n;++j){
				if(s[i][j]=='.')
					a[i][j]=-1;
				else
					a[i][j]=s[i][j]-'0';
			}
		}
		for(i=0;i<(n+1)*(n+1);++i)
			P[i]=i;
		
		DFS(0);
		for(i=0;i<n;++i){
			for(j=0;j<n;++j)
				if(b[i][j])
					printf("/");
				else
					printf("\\");
			printf("\n");
		}
	}
	return 0;
}

