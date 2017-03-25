#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Goods{
  unsigned num,s,p;
  Goods(unsigned num=0,unsigned s=0,unsigned p=0):num(num),s(s),p(p){}
};

template <typename T>
struct Queue{
  private:
	  vector<Goods> q;
	  T cmp;
	  void Ajust(unsigned node){
	  	unsigned i=node,j;
	  	while(i<<1<q.size()){
			  if((i<<1)+1<q.size()&&cmp(q[(i<<1)+1],q[i<<1]))
				  j=(i<<1)+1;
				else
				  j=i<<1;
				if(cmp(q[j],q[i])){
					Goods t=q[i];
					q[i]=q[j];
					q[j]=t;
					i=j;	
				}
				else
				 break;
			}
		}
		
	public:
	  Queue(unsigned s,unsigned p){
	  	q.resize(1);
	  	q[0]=Goods(0,s,p);
		}
		
		void clear(){
			q.resize(1);
		}
		
	  bool empty(){
	  	if(q.size()<=1)
	  	  return true;
	  	return false;
		}
		
	  void push(const Goods &p){
	  	if(p.s==0)
	  	  return;
		  q.push_back(p);
		  for(unsigned i=q.size()-1;i>1&&cmp(q[i],q[i/2]);i/=2){
			  Goods t=q[i];
			  q[i]=q[i/2];
			  q[i/2]=t;
		  }
	  };
	
	  Goods &top(){
	  	if(empty())
	  	  return q[0];
		  return q[1];
	  }
		
		void pop(){
			do{
	  	  q[1]=q[q.size()-1];
	  	  q.pop_back();
	  	  Ajust(1);
	  	}while(!empty()&&q[1].s==0);
		};
		
	  void delt(unsigned num){
	  	for(unsigned i=1;i<q.size();++i)
	  	  if(q[i].num==num){
	  	    q[i].s=0;
	  	    if(i==1)
	  	      pop();
	  	    break;
			  }
		}
		
		void output(){
			unsigned s,p,a=0,b=0;
			p=top().p;
			s=top().s;
			for(unsigned i=2;i<q.size();++i)
			  if(q[i].p==p)
			    s+=q[i].s;
			cout<<s<<' '<<p;
		}
};

struct Buy{
	bool operator () (const Goods &a,const Goods &b){
		if(a.p==b.p)
		  return a.num<b.num;
		return a.p>b.p;
	}
};

struct Sell{
	bool operator () (const Goods &a,const Goods &b){
		if(a.p==b.p)
		  return a.num<b.num;
		return a.p<b.p;
	}
};

Queue<Buy> buy(0,0);
Queue<Sell> sell(0,99999);
unsigned n,i=0;

void quote(){
	cout<<"QUOTE ";
	buy.output();
  cout<<" - ";
	sell.output();
	cout<<endl;
}

bool first=1;

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  
  while(cin>>n){
  	buy.clear();
  	sell.clear();
  	if(!first)
  	  cout<<endl;
  	first=0;
  	
		for(i=1;i<=n;++i){
  	  string str;
  	  cin>>str;
		  if(str!="CANCEL"){
		  	unsigned s,p;
		  	cin>>s>>p;
		  	Goods goods(i,s,p);
		  	if(str=="BUY"){
			  	while(!sell.empty()&&sell.top().p<=goods.p)
		  			if(sell.top().s<=goods.s){
		  				cout<<"TRADE "<<sell.top().s<<' '<<sell.top().p<<endl;
			  			goods.s-=sell.top().s;
			  			sell.pop();	
			  		}
				  	else{
				  		cout<<"TRADE "<<goods.s<<' '<<sell.top().p<<endl;
					  	sell.top().s-=goods.s;
					  	goods.s=0;
					  	break;
					  }
			    buy.push(goods);
			  }
			  else{
				  while(!buy.empty()&&buy.top().p>=goods.p)
				  	if(buy.top().s<=goods.s){
				  		cout<<"TRADE "<<buy.top().s<<' '<<buy.top().p<<endl;
				  		goods.s-=buy.top().s;
				  		buy.pop();
				  	}
				   	else{
				   		cout<<"TRADE "<<goods.s<<' '<<buy.top().p<<endl;
				  		buy.top().s-=goods.s;
				  		goods.s=0;
				  		break;
				  	}
			    sell.push(goods);  
			  }
		  }
		  else{
			  unsigned k;
			  cin>>k;
			  buy.delt(k);
			  sell.delt(k);  
		  }
			quote();
	  }
	}
  return 0;
}

