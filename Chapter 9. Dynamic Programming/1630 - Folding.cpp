#include<cstdio>
#include<cstring>

int i,j;
unsigned len,n;
unsigned d[110][110],a[110][110],k[110][110];
char s[110];
bool fold[110][110];

unsigned Numlen(unsigned n){
	unsigned cnt=0;
	do{
		n/=10;
		++cnt;
	}while(n);
	return cnt;
}

void PrintAns(unsigned i,unsigned len){
	if(len<=4){
		for(unsigned j=0;j<len;++j)
			printf("%c",s[i+j]);
		return;
	}
	if(fold[i][len]){
		printf("%u(",k[i][len]);
		PrintAns(i,len/k[i][len]);
		printf(")");
	}
	else{
		PrintAns(i,k[i][len]);
		PrintAns(i+k[i][len],len-k[i][len]);
	}
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);

	
	while(scanf("%s",s)!=EOF){
		memset(a,0,sizeof(a));
		n=strlen(s);
		
		for(len=1;len<=n/2;++len)
			for(i=n-len*2;i>=0;--i)
				if(strncmp(s+i,s+i+len,len)==0)
					a[i][len]=a[i+len][len]+1;
		for(len=1;len<=n;++len)
			for(i=0;i+len-1<n;++i){
				d[i][len]=len;
				fold[i][len]=0;
				k[i][len]=len/2;
				if(len>4){
					for(j=1;j<=len/2&&(len%j||a[i][j]+1<len/j);++j);
					if(j<=len/2){
						unsigned res=d[i][j]+Numlen(len/j)+2;
						if(d[i][len]>res){
							d[i][len]=res;
							fold[i][len]=1;
							k[i][len]=len/j;
						}
					}
					else
						for(j=1;j<len;++j)
							if(d[i][len]>d[i][j]+d[i+j][len-j]){
								d[i][len]=d[i][j]+d[i+j][len-j];
								k[i][len]=j;
							}
				}
			}
		PrintAns(0,n);
		printf("\n");
	}
	return 0;
}

