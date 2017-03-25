#include<cstdio>
#include<cstring>
#include<cctype>

const int maxi[]={0,0,4,16,64,256,1024,4096,16384,65536};

int Compute(char *s,unsigned l){
	int t=-1,i,j,ans=0;
	int a[10];
	a[j=0]=1;
	for(i=0;i<l;++i){
		if(isdigit(s[i])){
			if(t==0)
				return -1;
			if(t<0)
				t=0;
			t=t*10+s[i]-'0';
		}
		else{
			a[j]*=t;
			if(s[i]=='-')
				a[++j]=-1;
			else if(s[i]=='+')
				a[++j]=1;
			t=-1;
		}
	}
	a[j]*=t;
	for(i=0;i<=j;++i)
		ans+=a[i];
	return ans;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);

	bool solve;
	char s[20],ex[30];
	int i,j,k,T;
	unsigned l;
	for(T=1;scanf("%s",s)!=EOF&&s[0]!='=';++T){
		l=strlen(s)-1;
		printf("Problem %d\n",T);
		solve=0;
		for(i=0;i<maxi[l]-1;++i){
			for(j=0,k=0;j<l-1;++j){
				ex[k++]=s[j];
				switch(i>>(l-j-2)*2&3){
					case 0:ex[k++]='*';break;
					case 1:ex[k++]='+';break;
					case 2:ex[k++]='-';
				}
				
			}
			ex[k++]=s[j];
			ex[k]=0;
			if(Compute(ex,k)==2000){
				printf("  %s=\n",ex);
				solve=1;
			}
		}
		if(!solve)
			printf("  IMPOSSIBLE\n");
	}
	return 0;
}

