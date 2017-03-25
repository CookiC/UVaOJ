#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
unsigned image[100][100];
vector<unsigned> tree;

int DFS(unsigned bx,unsigned by,unsigned ex,unsigned ey,unsigned node){  
	if(bx==ex)
    return image[bx][by];
  int leaf[4];
  unsigned i;
	leaf[0]=DFS(bx,by,(bx+ex)/2,(by+ey)/2,node*10+1);
  leaf[1]=DFS(bx,(by+ey)/2+1,(bx+ex)/2,ey,node*10+2);
  leaf[2]=DFS((bx+ex)/2+1,by,ex,(by+ey)/2,node*10+3);
  leaf[3]=DFS((bx+ex)/2+1,(by+ey)/2+1,ex,ey,node*10+4);
  if(leaf[0]==0&&leaf[1]==0&&leaf[2]==0&&leaf[3]==0)
    return 0;
  if(leaf[0]==1&&leaf[1]==1&&leaf[2]==1&&leaf[3]==1)
    return 1;
  for(i=0;i<4;++i)
    if(leaf[i]==1)
      tree.push_back(node*10+i+1);
  return -1;
}

void Image(){
	unsigned i,j,sum=0;
	int root;
	tree.clear();
	for(i=1;i<=n;++i){
		char c;
	  j=1;
		while(j<=n){
			c=getchar();
			if(c=='0'||c=='1'){
	      image[i][j]=c-'0';
	      ++j;
			}
	  }
	}
	root=DFS(1,1,n,n,0);
	if(root==1)
	  tree.push_back(0);
	for(i=0;i<tree.size();++i){
	  unsigned t=tree[i];
	  tree[i]=0;
	  while(t>0){
	  	tree[i]=tree[i]*5+t%10;
	  	t/=10;
		}
	}
	sort(tree.begin(),tree.end());
	for(i=0;i<tree.size();++i)
	  if(i%12==0)
	    printf("\n%u",tree[i]);
	  else
	    printf(" %u",tree[i]);
	printf("\nTotal number of black nodes = %u\n",tree.size());
}

void Paint(unsigned node){
	unsigned bx=1,by=1,ex=n,ey=n;
	while(node>0){
		switch(node%5){
			case 1:ex=(bx+ex)/2;ey=(by+ey)/2;break;
			case 2:ex=(bx+ex)/2;by=(by+ey)/2+1;break;
			case 3:bx=(bx+ex)/2+1;ey=(by+ey)/2;break;
			case 4:bx=(bx+ex)/2+1;by=(by+ey)/2+1;
		}
		node/=5;
	}
	for(unsigned i=bx;i<=ex;++i)
	  for(unsigned j=by;j<=ey;++j)
	    image[i][j]=1;
}

void Tree(){
	unsigned i,j;
	int m;
	memset(image,0,sizeof(image));
	while(scanf("%d",&m)!=EOF&&m>=0)
	  Paint(m);
	for(i=1;i<=n;++i){
		printf("\n");
	  for(j=1;j<=n;++j)
	    if(image[i][j])
	      printf("*");
	    else
	      printf(".");
	}
	printf("\n");
}

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  for(unsigned T=1;scanf("%d",&n)!=EOF&&n;++T){
		if(T!=1)
		  printf("\n");
		printf("Image %u",T);
  	if(n>0)
  	  Image();
  	else{
  		n=-n;
  	  Tree();
  	}
  }
  return 0;
}

