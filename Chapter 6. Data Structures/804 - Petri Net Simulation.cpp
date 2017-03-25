#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

struct Transition{
	vector<unsigned> input,in,output,on;
	void clear(){
		input.clear();
		in.clear();
		output.clear();
		on.clear();
	}
};

unsigned NP,NT=0,NF;
unsigned place[110];
Transition tran[110];

void Initial(){
	unsigned i;
	memset(place,0,sizeof(place));
	for(i=0;i<NT;++i)
	  tran[i].clear();
}

void Firing(){
	unsigned i,j,k;
	for(i=0;i<NF;++i){
		for(j=0;j<NT;++j){
		  for(k=0;k<tran[j].input.size()&&place[tran[j].input[k]]>=tran[j].in[k];++k);
		  if(k>=tran[j].input.size()){
		    for(k=0;k<tran[j].input.size();++k)
				  place[tran[j].input[k]]-=tran[j].in[k];
				for(k=0;k<tran[j].output.size();++k)
				  place[tran[j].output[k]]+=tran[j].on[k];
				break;
		  }
		}
		if(j>=NT)
		  break;
	}
  if(i<NF)
    printf(" dead after %u transitions\n",i);
  else
    printf(" still live after %u transitions\n",NF);
  printf("Places with tokens:");
  for(i=1;i<=NP;++i)
    if(place[i])
      printf(" %u (%u)",i,place[i]);
  printf("\n\n");
}

unsigned i,j,T;

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  for(T=1;scanf("%u",&NP)!=EOF&&NP;++T){
    Initial();
    printf("Case %u:",T);
    for(i=1;i<=NP;++i)
	    scanf("%u",&place[i]);
	  scanf("%u",&NT);
	  for(i=0;i<NT;++i){
		  int n;
		  unsigned input[110]={0},output[110]={0};
	    while(scanf("%d",&n)!=EOF&&n)
		    if(n<0)
		  	  ++input[-n];
			  else
			    ++output[n];
			for(j=1;j<=NP;++j)
			  if(input[j]){
			  	tran[i].input.push_back(j);
			  	tran[i].in.push_back(input[j]);
				}
			for(j=1;j<=NP;++j)
			  if(output[j]){
			  	tran[i].output.push_back(j);
			  	tran[i].on.push_back(output[j]);
				}
	  }
	  scanf("%u",&NF);	  
		Firing();
	}
  return 0;
}

