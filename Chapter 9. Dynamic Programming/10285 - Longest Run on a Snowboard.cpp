#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int N,R,C,i,j;
string name;
int Max;
int d[101][101];
unsigned a[101][101];
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

int Dp(unsigned x,unsigned y){
	if(d[x][y]>0)
		return d[x][y];
	d[x][y]=1;
	for(unsigned i=0;i<4;++i){
		int vx=x+dx[i];
		int vy=y+dy[i];
		if(0<=vx&&vx<R&&0<=vy&&vy<C&&a[vx][vy]<a[x][y]&&Dp(vx,vy)+1>d[x][y])
			d[x][y]=Dp(vx,vy)+1;
	}
	return d[x][y];
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	cin>>N;
	while(N--){
		memset(d,0,sizeof(d));
		
		cin>>name>>R>>C;
		for(i=0;i<R;++i)
			for(j=0;j<C;++j)
				cin>>a[i][j];
		
		Max=0;
		for(i=0;i<R;++i)
			for(j=0;j<C;++j)
				if(Dp(i,j)>Max)
					Max=Dp(i,j);
		
		cout<<name<<": "<<Max<<endl;
	}
	return 0;
}

