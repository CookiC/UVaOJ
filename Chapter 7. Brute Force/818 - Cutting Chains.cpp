#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;

struct Node{
	unsigned n;
	Node *next;
};

struct AdjacencyList{
	  vector<unsigned> size;
    vector<Node*> head;
		void initial(unsigned n){
			unsigned i;
			for(i=0;i<head.size();++i)
			  for(Node *p=head[i];head[i]!=NULL;p=head[i]){
			  	head[i]=head[i]->next;
			  	delete p;
				}
			head.resize(n+1,NULL);
			size.clear();
			size.resize(n+1,0);
			for(i=0;i<=n;++i)
			  head[i]=NULL;
		}
		
		
		void insert(unsigned u,unsigned v){
			Node *p;
			for(p=head[u];p!=NULL;p=p->next)
			  if(p->n==v)
			    return;
			p=new Node;
			p->n=v;
			p->next=head[u];
			head[u]=p;
			++size[u];
		}
		
		void erase(unsigned u,unsigned v){
		  Node *p,*q;
		  --size[u];
			if(head[u]->n==v){
			  p=head[u];
			  head[u]=p->next;
			  delete p;
			  return;
		  }
			for(Node *p=head[u];p!=NULL;p=p->next){
			  if(p->n==v){
			  	q->next=p->next;
			  	delete p;
			  	break;
				}
			  q=p;
			}
		}
		
		Node* operator [](const unsigned n){
			return head[n];
		}
		
		void print(){
			printf("\n");
			for(unsigned i=1;i<head.size();++i){
				printf("%4u:",i);
			  for(Node *p=head[i];p!=NULL;p=p->next)
			    printf("%3u",p->n);
			  printf("\n");
			}
		}
};

unsigned n,ans;
AdjacencyList G;

unsigned find(unsigned x,unsigned uFind[]){
	return uFind[x]==x?x:uFind[x]=find(uFind[x],uFind);
}

bool update(unsigned uFind[],int state[]){
	unsigned i;
	bool res=true;
	memset(state,0,16*sizeof(int));

  for(i=1;i<=n;++i)
  	  uFind[i]=i;
  for(i=1;i<=n;++i)
    for(Node *p=G[i];p!=NULL;p=p->next){
    	unsigned x=find(i,uFind),y=find(p->n,uFind);
    	uFind[x]=y;
		}

  for(i=1;i<=n;++i)
  	if(state[find(i,uFind)]>=0){
  		if(G.size[i]<=1)
  	    ++state[uFind[i]];
  	  else if(G.size[i]>=3)
  	    state[uFind[i]]=-1;
  	}

  for(i=1;i<=n;++i)
    if(uFind[i]==i&&state[i]<=0){
		    state[i]=0;
		    res=false;
	  }
  return res;
}

void DFS(unsigned deep,unsigned begin){
	unsigned i;
	unsigned uFind[16];
	int state[16];
	if(update(uFind,state)){
		unsigned sum=0,single=0,res;
    for(i=1;i<=n;++i)
      if(uFind[i]==i&&state[i]){
        ++sum;
        if(state[i]==1)
          ++single;
      }
	  if(deep+1>=sum-deep)
		  res=deep;
		else if(single+1>=sum-single)
		  res=sum/2;
		else
		  res=sum-single-1;
		if(ans>res)
		  ans=res;
		return;
	}
	
	for(i=begin;i<=n;++i)
	  if(!state[uFind[i]]){
	  	Node *q=G[i];
	  	unsigned size=G.size[i];
	  	for(Node *p=G[i];p!=NULL;p=p->next)
	  		G.erase(p->n,i);
	  	G.head[i]=NULL;
	  	G.size[i]=0;
	  	DFS(deep+1,i+1);
	  	G.head[i]=q;
	  	G.size[i]=size;
	  	for(Node *p=G[i];p!=NULL;p=p->next)
	  	  G.insert(p->n,i);
		};
}

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  for(unsigned T=1;scanf("%u",&n)!=EOF&&n;++T){
  	G.initial(n);
  	ans=0xFFFFFFFF;
  	printf("Set %u: ",T);

  	int tu,tv;
  	while(scanf("%d%d",&tu,&tv)!=EOF&&tu>0){
  		G.insert(tu,tv);
  	  G.insert(tv,tu);
  	}
 	  DFS(0,1);
 	  printf("Minimum links to open is %u\n",ans);
	}
//	double ck=(double)clock()/CLOCKS_PER_SEC; 
//	printf("Time used=%.2fs=%.2fmin=%.2fh\n",ck,ck/60,ck/360);
  return 0;
}

