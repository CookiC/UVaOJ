#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;

char stk[200],str[200];
unsigned n,i,j,len,top;
bool b;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	scanf("%u\n",&n);
	for(i=0;i<n;++i){
	  cin.getline(str,200);
	  len=strlen(str);
	  top=0;
	  b=true;
	  
	  for(j=0;j<len&&b;++j)
	  	switch(str[j]){
	  		case '(':stk[top++]='(';break;
	  		case ')':
				  if(top>0&&stk[top-1]=='(')
					  --top;
					else
					  b=false;
					break;
				case '[':stk[top++]='[';break;
				case ']':
				  if(top>0&&stk[top-1]=='[')
					  --top;
					else
					  b=false;
			}
		if(top!=0)
		  b=false;
		if(b)
		  printf("Yes\n");
		else
		  printf("No\n");
	}
  return 0;
}

