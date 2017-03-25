#include<cstdio>
#include<cstring>
#include<cstdlib>

bool used[30];
unsigned cnt;
unsigned pip[7][8],lab[7][8];
unsigned dom[7][7]={{1, 2, 3, 4, 5, 6, 7},
                    {2, 8, 9,10,11,12,13},
										{3, 9,14,15,16,17,18},
										{4,10,15,19,20,21,22},
										{5,11,16,20,23,24,25},
										{6,12,17,21,24,26,27},
										{7,13,18,22,25,27,28}};

void DFS(int u,unsigned deep){
	if(deep>=28){
		for(unsigned i=0;i<7;++i){
		  for(unsigned j=0;j<8;++j)
		    printf("%4u",lab[i][j]);
		  printf("\n");
		}
		printf("\n\n");
		++cnt;
		return;
	}
	
	while(*(lab[0]+u))
	  ++u;

	unsigned ux=u/8;
	unsigned uy=u%8;
	unsigned vlab;
	if(ux+1<7&&!lab[ux+1][uy]){
	  vlab=dom[pip[ux][uy]][pip[ux+1][uy]];
	  if(!used[vlab]){
	  	lab[ux][uy]=lab[ux+1][uy]=vlab;
	  	used[vlab]=true;
		  DFS(u+1,deep+1);
		  lab[ux][uy]=lab[ux+1][uy]=0;
		  used[vlab]=false;
	  }
	}
	if(uy+1<8&&!lab[ux][uy+1]){
	  vlab=dom[pip[ux][uy]][pip[ux][uy+1]];
	  if(!used[vlab]){
	  	lab[ux][uy]=lab[ux][uy+1]=vlab;
	  	used[vlab]=true;
		  DFS(u+2,deep+1);
		  lab[ux][uy]=lab[ux][uy+1]=0;
		  used[vlab]=false;
	  }
	}
	
}

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  unsigned i,j;
	for(unsigned T=0;scanf("%u",&pip[0][0])!=EOF;++T){
		memset(lab,0,sizeof(lab));
		memset(used,0,sizeof(used));
    cnt=0;
    
		if(T)
      printf("\n\n\n\n\n");
    printf("Layout #%u:\n\n\n",T+1);
    
    printf("%4u",pip[0][0]);
		for(i=0;i<7;++i){
      for(j=0;j<8;++j)
        if(i||j){
          scanf("%u",&pip[i][j]);
          printf("%4u",pip[i][j]);
        }
      printf("\n");
    }
    
    printf("\nMaps resulting from layout #%u are:\n\n\n",T+1);
    DFS(0,0);
    printf("There are %u solution(s) for layout #%u.\n",cnt,T+1);
  }
  return 0;
}

