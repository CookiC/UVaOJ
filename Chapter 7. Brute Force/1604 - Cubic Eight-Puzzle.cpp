#include<iostream>
#include<cmath>
#include<cstring>
#define Mod 500000
using namespace std;

//(0,E,E),(1,W,R),(2,W,B),(3,R,W),(4,R,B),(5,B,W),(6,B,R)
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
const unsigned cvt[][4]={{0,0,0,0},{3,3,6,6},{5,5,4,4},{1,1,5,5},{6,6,2,2},{2,2,3,3},{4,4,1,1}};

unsigned Code(char *b){
	unsigned sum=0;
	for(int i=0;i<9;++i)
		sum=sum*7+b[i];
	return sum;
}

void Decode(unsigned code,char *b){
	for(int i=8;i>=0;--i){
		b[i]=code%7;
		code/=7;
	}
}

unsigned Compare(char *d,char *b){
	unsigned cnt=0;
	for(int i=0;i<9;++i)
		if(d[i]!=(b[i]+1)/2)
			++cnt;
	return cnt;
}

bool dup[50000000];
int f,r;
unsigned q[500000];
char borad[3][3],dest[3][3];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	int ux,uy,x,y,i,j;
	char ub[3][3],uf[3][3];
	while(cin>>uy>>ux&&(uy||ux)){
		memset(ub,1,sizeof(ub));
		ub[--ux][--uy]=0;
		for(i=0;i<3;++i)
			for(j=0;j<3;++j){
				char c;
				cin>>c;
				switch(c){
					case 'E':dest[i][j]=0;x=i;y=j;break;
					case 'W':dest[i][j]=1;break;
					case 'R':dest[i][j]=2;break;
					case 'B':dest[i][j]=3;
				}
			}
		
		int cntu=1,cntv=0,deep=0,cnt=0;
		unsigned uz=Code(ub[0]);
		
		memset(dup,0,sizeof(dup));
		f=r=0;
		q[r++]=uz;
		dup[uz]=1;
		
		while(f<r&&deep<=30){
			++cnt;
			if(!cntu--){
				++deep;
				cntu=cntv-1;
				cntv=0;
			}
			uz=q[f++%Mod];
			Decode(uz,ub[0]);
			for(i=0;i<9&&*(ub[0]+i);++i);
			ux=i/3;
			uy=i%3;
			if(!(uz=Compare(dest[0],ub[0])))
				break;
			if(uz+deep>31)
				continue;
			for(i=0;i<4;++i){
				int vx=ux+dx[i];
				int vy=uy+dy[i];
				if(0<=vx&&vx<3&&0<=vy&&vy<3){
					ub[ux][uy]=cvt[ub[vx][vy]][i];
					ub[vx][vy]=0;
					unsigned vz=Code(ub[0]);
					if(!dup[vz]){						
						dup[vz]=1;
						q[r++%Mod]=vz;
						++cntv;
					}
					ub[vx][vy]=cvt[ub[ux][uy]][i];
					ub[ux][uy]=0;
				}
			}
		}
		if(f!=1&&f>=r||deep>30)
			cout<<-1<<endl;
		else
			cout<<deep<<endl;
	}
	return 0;
}

