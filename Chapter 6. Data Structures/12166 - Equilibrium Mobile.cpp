#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int T;
unsigned d;
string s;
unsigned w[20];
vector<unsigned> tree[20];

void ExTree(const string &s,unsigned deep){
	unsigned i,len=s.size();
	if(deep>d)
	  d=deep;
	if(s[0]=='['&&s[len-1]==']'){
		unsigned j=0,mid;
		for(i=1;i<len-1;++i){
			if(s[i]=='[')
			  ++j;
			if(s[i]==']')
			  --j;
			if(s[i]==','&&j==0){
				mid=i;
				break;
			}
		}
		ExTree(s.substr(1,mid-1),deep+1);
		ExTree(s.substr(mid+1,len-mid-2),deep+1);
	}
	else{
		unsigned sum=0;
	  for(i=0;i<len;++i)
	    sum=sum*10+s[i]-'0';
		tree[deep].push_back(sum);
	}
}

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
	cin>>T;
  while(T--){
  	int i,j;
  	unsigned least=0xFFFFFFFF;
  	
  	cin>>s;
		d=0;
		for(i=0;i<20;++i)
		  tree[i].clear();
  	ExTree(s,0);
  	++d;
		for(i=0;i<d;++i)
  	  for(j=0;j<tree[i].size();++j){
  	  	int k,l;
				unsigned count=0;
  	  	w[i]=tree[i][j];
  	  	for(k=i-1;k>=0;--k)
  	  	  w[k]=w[k+1]*2;
  	  	for(k=i+1;k<d;++k)
  	  	  if(w[k-1]%2==0)
  	  	    w[k]=w[k-1]/2;
  	  	while(k<d){
  	  		w[k]=0;
  	  		++k;
				}
				
				for(k=0;k<d;++k)
  	      for(l=0;l<tree[k].size();++l)
  	        if(tree[k][l]!=w[k])
  	          ++count;
  	    if(least>count)
  	      least=count;
			}
		cout<<least<<endl;
	}
  return 0;
}

