#include<iostream>
#include<queue>
#include<set>
using namespace std;

unsigned hand[52];
unsigned hf,hr;

class Pile{
private:
	unsigned q[52];
	unsigned f,r;
	
public:
	void clear(){
		f=0;
		r=0;
	}
	
	bool plan(unsigned i,unsigned j,unsigned k){
		unsigned sum=q[i]+q[j]+q[k];
		if(sum==10||sum==20||sum==30){
			hand[hr++%52]=q[i];
			hand[hr++%52]=q[j];
			hand[hr++%52]=q[k];
			return true;
		}
		return false;
	}
	
	void push(unsigned v){
		q[(r++)%52]=v;
		while(r-f>=3){
		  if(plan(f%52,(f+1)%52,(r-1)%52)){
		  	f+=2;
		  	--r;
		  	continue;
			}
		  if(plan(f%52,(r-2)%52,(r-1)%52)){
		  	++f;
		  	r-=2;
		  	continue;
			}
		  if(plan((r-3)%52,(r-2)%52,(r-1)%52)){
		  	r-=3;
		  	continue;
			}
			return;
		}
	}
	
	bool empty(){
		return r<=f;
	}
	
	void Print(){
		unsigned i;
		for(i=f;i<r;++i)
		  printf("%u ",q[i%52]);
		printf("\n");
	}
	
	bool operator < (const Pile &b) const{
		if(r-f==b.r-b.f)
	    for(unsigned i=0;i<r-f;++i)
	      if(q[(f+i)%52]!=b.q[(b.f+i)%52])
	        return q[(f+i)%52]<b.q[(b.f+i)%52];
		return r-f<b.r-b.f;
	}
	
	bool operator != (const Pile &b) const{
		if(r-f==b.r-b.f){
	    for(unsigned i=0;i<r-f;++i)
	      if(q[(f+i)%52]!=b.q[(b.f+i)%52])
	        return true;
	    return false;
	  }
	  return true;
	}
};

struct State{
	unsigned f,r,n;
	unsigned h[52];
  Pile p[8];
  State(unsigned f0,unsigned r0,unsigned n0,unsigned h0[],Pile p0[]){
  	unsigned i;
		f=f0;
  	r=r0;
  	n=n0;
  	for(i=f;i<r;++i)
  	  h[i%52]=h0[i%52];
  	for(i=0;i<n;++i)
  	  p[i]=p0[i];
	}
	
	bool operator < (const State &b) const{
		if(n==b.n){
			if(r-f==b.r-b.f){
				unsigned i;
				for(i=0;i<r-f;++i)
				  if(h[(f+i)%52]!=b.h[(b.f+i)%52])
				    return h[(f+i)%52]<b.h[(b.f+i)%52];
				for(i=0;i<n;++i)
				  if(p[i]!=b.p[i])
				    return p[i]<b.p[i]; 
			}
			return r-f<b.r-b.f;
		}
		return n<b.n;
	}
};

Pile p[8];
set<State> s;

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  unsigned v,n,k;
  int i,j;
  while(cin>>v&&v){
  	n=7;
    hr=hf=0;
    s.clear();
  	for(i=0;i<8;++i)
  	  p[i].clear();
  	
		hand[hr++]=v;
    for(i=1;i<52;++i){
  	  cin>>v;
    	hand[hr++]=v;
//    	printf("%d ",i);
  	}
	  k=0;
		do{
		  for(i=0;i<n&&hf<hr&&s.find(State(hf,hr,n,hand,p))==s.end();++i){
				s.insert(State(hf,hr,n,hand,p));
				p[i].push(hand[hf++%52]);
				++k;
				if(p[i].empty()){
		      for(j=i;j<n;++j)
		        p[j]=p[j+1];
		      --n;
		      --i;
		    }
		  }
	  }while(hf<hr&&!p[0].empty()&&s.find(State(hf,hr,n,hand,p))==s.end());
	  
	  if(p[0].empty())
	    cout<<"Win : "<<k<<endl;
	  if(hf>=hr)
	    cout<<"Loss: "<<k<<endl;
	  if(s.find(State(hf,hr,n,hand,p))!=s.end()){
	    cout<<"Draw: "<<k<<endl;
		}
  }
  return 0;
}

