#include<cstdio>
#include<cstring>

void DFS(char Dlr[],char Ldr[],char Lrd[],unsigned len){
	unsigned mid,i;
	Lrd[len-1]=Dlr[0];
	for(i=0;Ldr[i]!=Dlr[0];++i);
	mid=i;
	if(mid>0)
	  DFS(&Dlr[1],&Ldr[0],&Lrd[0],mid);
	if(mid<len-1)
	  DFS(&Dlr[mid+1],&Ldr[mid+1],&Lrd[mid],len-mid-1);
}

char Dlr[100],Ldr[100],Lrd[100];

int main(){
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
  
  while(scanf("%s%s",Dlr,Ldr)!=EOF){
  	memset(Lrd,0,sizeof(Lrd));
    DFS(Dlr,Ldr,Lrd,strlen(Dlr));
    printf("%s\n",Lrd);
  }
  return 0;
}

