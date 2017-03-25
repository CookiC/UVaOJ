#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<ctime>
#define maxindex 100010
using namespace std;

struct BigInt
{
  vector<int> s;
  
  inline void clear(){
  	s.clear();
	}
	
	inline int size() const{
		return s.size();
	}
	
	inline void push_back(int a){
		s.push_back(a);
	}
	
	inline int &operator [](unsigned i){
		return s[i];
	}

  inline int operator [](unsigned i) const{
		return s[i];
	}
  //构造函数 创建该结构体是初值为0 
  BigInt(){s.push_back(0);}  
  
  //整型到高精度的转换（赋值） 
  BigInt operator = (int b){
  	s.clear();
  	do{
	    s.push_back(b%10);
	    b/=10;
	  }while(b>0);
	  return *this;
  }
  
  bool operator < (const BigInt& b) const{ 
  	for(unsigned i=1;i<=s.size()&&i<=b.s.size();++i)
  	  if(s[s.size()-i]!=b.s[b.s.size()-i])
  	    return s[s.size()-i]<b.s[b.s.size()-i];
  	return s.size()<b.s.size();
  }
  
  BigInt operator + (const BigInt& b) const{
    BigInt c;
    int i,g,x,l=s.size(),lb=b.s.size();
    c.s.clear();
    for(i=0,g=0;g!=0||i<l||i<lb;i++){
      x=g;
      if(i<l) x+=s[i];
      if(i<lb) x+=b.s[i];
      c.s.push_back(x%10);
      g=x/10;
    }
    return c;
  }

  void print() const
  {
  	for(int i=s.size()-1;i>=0;i--)
  	  printf("%d",s[i]);
  	printf("\n");
  }
};

map<BigInt,int> m;
BigInt a,b,c,d,e;
unsigned i;
int j;
string str;

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);

	a=1;
	b=1;
	m[a]=0;
	for(i=2;i<100000;++i){
	  c=a+b;
	  if(c.size()>52){
	  	d.clear();
	    e.clear();
	    for(j=a.size()-51;j>=0&&j<a.size();++j)
	  	  d.push_back(a[j]);
	  	for(j=c.size()-52;j>=0&&j<c.size();++j)
	  	  e.push_back(c[j]);
	  	b=d;
	  	a=e;
	  }
	  else{
		  b=a;	
	  	a=c;
	  }
	  if(!m.count(c))
	    m[c]=i;
  }

	unsigned n,k;
	cin>>n;
	for(i=1;i<=n;++i){
	  cout<<"Case #"<<i<<": ";
	  cin>>str;
	  a.clear();
	  for(j=str.size()-1;j>=0;--j)
	    a.push_back(str[j]-'0');
	  if(!m.count(a)){
	  	auto p=m.insert(make_pair(a,-1));
	  	auto now=p.first;
	  	auto next=p.first;
	  	unsigned mini=maxindex;
			for(++next;next!=m.end();++next){
	  	  const BigInt &b=next->first;
	  	  for(j=1;j<=a.size()&&j<=b.size()&&a[a.size()-j]==b[b.size()-j];++j);
			  if(j>a.size()){
				  if(next->second<mini)
	  	      mini=next->second;
	  	  }
	  	  else
	  	    break;
	  	}
	    if(mini!=maxindex)
	      cout<<mini<<endl;
	    else
	      cout<<-1<<endl;
			m.erase(now);
		}
		else
		  cout<<m[a]<<endl;
	}
//	printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC);
  return 0;
}

