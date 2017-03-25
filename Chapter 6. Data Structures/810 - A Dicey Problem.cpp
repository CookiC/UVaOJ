#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<set>
using namespace std;

string name;
unsigned r,c,r0,c0,front,top;
unsigned i,j,len;
int maze[20][20];
unsigned wayx[1000],wayy[1000];
//unsigned die[6];//前0 后1 左2 右3 上4 下5
set<unsigned> s;
int dx[4]={1,-1,0,0},dy[4]={0,0,-1,1};
const unsigned pose[24][6]={{1,6,4,3,5,2},{1,6,3,4,2,5},{1,6,2,5,4,3},{1,6,5,2,3,4},
                            {2,5,3,4,6,1},{2,5,4,3,1,6},{2,5,1,6,3,4},{2,5,6,1,4,3},
											      {3,4,2,5,1,6},{3,4,5,2,6,1},{3,4,6,1,2,5},{3,4,1,6,5,2},
							       				{4,3,6,1,5,2},{4,3,1,6,2,5},{4,3,2,5,6,1},{4,3,5,2,1,6},
									       		{5,2,4,3,6,1},{5,2,3,4,1,6},{5,2,1,6,4,3},{5,2,6,1,3,4},
											      {6,1,3,4,5,2},{6,1,4,3,2,5},{6,1,2,5,3,4},{6,1,5,2,4,3}};
const unsigned turn[4][6]={{5,4,2,3,0,1}, //前 
				                   {4,5,2,3,1,0}, //后 
				                   {0,1,5,4,2,3}, //左 
				                   {0,1,4,5,3,2}};//右 

unsigned code(unsigned die[6],unsigned x,unsigned y){
	unsigned i,st=0;
	for(i=0;i<6;++i)
	  st=st*7+die[i];
	st=st*15+x;
	st=st*15+y;
	return st;
}

void decode(unsigned st,unsigned die[6],unsigned &x,unsigned &y){
	int i;
	y=st%15;st/=15;
	x=st%15;st/=15;
	for(i=5;i>=0;--i){
	  die[i]=st%7;
	  st/=7;
	} 
}

unsigned Initial(){
	unsigned die[6],i,j;
	for(i=0;i<24;++i)
	  if(pose[i][0]==front&&pose[i][4]==top){
	  	for(j=0;j<6;++j){
	  	  die[j]=pose[i][j];
//	  	  cout<<die[j]<<',';
	  	}
//	  	cout<<endl;
	  	break;
		}
	s.clear();
	len=0;
	return code(die,r0,c0);
}



bool DFS(unsigned ust,unsigned deep){
	int i;
	unsigned udie[6],vdie[6],vst,ux,uy;
	decode(ust,udie,ux,uy);
//	cout<<ux<<','<<uy<<endl;
//	for(i=0;i<6;++i)
//	  cout<<udie[i]<<',';
//	cout<<endl;
//	cout<<ux<<' '<<uy<<' '<<deep<<endl;
	if(deep&&ux==r0&&uy==c0){
		wayx[deep]=ux;
		wayy[deep]=uy;
		len=deep;
	  return true;
	}
	
	for(i=0;i<4;++i){
	  unsigned vx=ux+dx[i];
	  unsigned vy=uy+dy[i];
	  if(1<=vx&&vx<=r&&1<=vy&&vy<=c&&(maze[vx][vy]<0||maze[vx][vy]==udie[4])){
	    for(j=0;j<6;++j)
	      vdie[turn[i][j]]=udie[j];
//	    	cout<<vx<<' '<<vy<<endl;
	    vst=code(vdie,vx,vy);
	    if(s.find(vst)==s.end()){
				s.insert(vst);
				if(DFS(vst,deep+1)){
				  wayx[deep]=ux;
				  wayy[deep]=uy;
				  return true;
				}
				s.erase(vst);
			}
	  }
	}
	return false;
//	cout<<deep<<endl;
}

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  while(cin>>name&&name!="END"){
  	cin>>r>>c>>r0>>c0>>top>>front;
  	for(i=1;i<=r;++i)
  	  for(j=1;j<=c;++j)
  	    cin>>maze[i][j];
  	
		unsigned st0=Initial();
		
		cout<<name;  	
		if(DFS(st0,0))
  	  for(i=0;i<=len;++i){
  	    if(i%9==0)
  	      cout<<"\n  ";
  	    cout<<'('<<wayx[i]<<','<<wayy[i]<<')';
  	    if(i!=len)
  	      cout<<',';
  	  }
  	else
  	  cout<<"\n  No Solution Possible";
  	cout<<endl;
  }
  return 0;
}

