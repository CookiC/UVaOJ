#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<iomanip>
using namespace std;

unsigned r,c;
string s[30][20];
int sheet[30][20];
bool inqed[30][20],inqing[30][20],re[30][20];

bool inquiry(unsigned x,unsigned y){
	string::iterator p;
	int &m=sheet[x][y],num;
	bool sign=false;
	inqing[x][y]=true;
	
	m=0;
	for(p=s[x][y].begin();p!=s[x][y].end();++p){
		num=0;
		if(*p=='-')
			sign=true;
		else if(*p=='+')
			sign=false;
		else{
		  if(isalpha(*p)){
		  	unsigned vx=*p++-'A';
		  	unsigned vy=*p++-'0';
	 	  	if(!inqing[vx][vy]&&(inqed[vx][vy]||inquiry(vx,vy)))
	  			  num=sheet[vx][vy];
		  	else
			  	return false;
		  }
		  else
		    while(isdigit(*p))
		  	  num=num*10+*p++-'0';
		  --p;
		  if(sign)
		  	num=-num;
		  m+=num;
		}
  }
	inqed[x][y]=true;
	inqing[x][y]=false;
	return true;
};

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  unsigned i,j;  
  while(cin>>r>>c&&r){
  	memset(inqed,0,sizeof(inqed));
  	memset(inqing,0,sizeof(inqing));
  	memset(re,0,sizeof(re));

  	for(i=0;i<r;++i)
  	  for(j=0;j<c;++j)
  	    cin>>s[i][j];
  	
  	bool mode=false;
  	for(i=0;i<r;++i)
  	  for(j=0;j<c;++j)
  	    if(!inqed[i][j]){
  	      re[i][j]=!inquiry(i,j);
  	      mode|=re[i][j];
  	    }
  	
  	if(mode){
  		for(i=0;i<r;++i)
  		  for(j=0;j<c;++j)
  		    if(re[i][j])
  		      cout<<char(i+'A')<<j<<": "<<s[i][j]<<endl;
  	}
		else{
			cout<<' ';
			for(i=0;i<c;++i)
  		  cout<<setw(6)<<i;
  		cout<<endl;
  	  for(i=0;i<r;++i){
  	  	cout<<char(i+'A');
  	    for(j=0;j<c;++j)
  	      cout<<setw(6)<<sheet[i][j];
  	    cout<<endl;
  	  }
		}
		cout<<endl;
	}
  return 0;
}

