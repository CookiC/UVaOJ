#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define LL long long unsigned
using namespace std;

inline LL first(LL a,LL b){
	LL i;
	for(i=b/a;b>a*i;++i);
	return i;
}

LL gcd(LL a,LL b){
	LL c;
	while(b%a!=0){
		c=a;
		a=b%a;
		b=c;
	}
	return a;
}

struct Fraction{
	LL n,d;
	Fraction(unsigned n,unsigned d):n(n),d(d){}
	Fraction operator - (const Fraction &b) const{
		LL c=d*b.d,an=n*b.d,bn=b.n*d;
		LL res=an-bn;
		an=gcd(res,c);
		return Fraction(res/an,c/an);
	}
	bool operator < (const Fraction &b) const{
		return n*b.d<b.n*d;
	}
};

unsigned maxd;
LL ans[100];
bool forbid[1010];
 
bool DFS(unsigned d,LL begin,Fraction dest){
	static LL res[100];
	int i;
	if(d>=maxd-1){
		if(dest.n==1&&dest.d>=begin&&(dest.d>1000||!forbid[dest.d])){
	  		res[d]=dest.d;
	  		for(i=maxd-1;res[i]<=ans[i];--i)
		    	if(res[i]<ans[i]){
		    		memcpy(ans,res,maxd*sizeof(LL));
		      		break;
		    	}
		  	return true;
	  	}
		return false;
	}
	bool b=false;
	begin=max(begin,first(dest.n,dest.d));
	for(i=begin;dest<Fraction(maxd-d,i);++i)
		if(i>1000||!forbid[i]){
			res[d]=i;
			if(DFS(d+1,i+1,dest-Fraction(1,i)))
				b=true;
		}
	return b;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
  
	int T;
	unsigned j,k;
	LL a,b,f;
	cin>>T;
	for(unsigned i=1;i<=T;++i){
		memset(forbid,0,sizeof(forbid));
		memset(ans,0xFF,sizeof(ans));
		
		cin>>a>>b>>k;
		for(j=0;j<k;++j){
			cin>>f;
			if(f>1000)
				return 0;
			forbid[f]=true;
		}
		
		f=first(a,b);
		for(maxd=1;!DFS(0,f,Fraction(a,b));++maxd);
		
		cout<<"Case "<<i<<": "<<a<<'/'<<b<<'=';
		for(j=0;j<maxd;++j){
			if(j)
		    	cout<<'+';
			cout<<"1/"<<ans[j];
		}
		cout<<'\n';
	}
	return 0;
}

