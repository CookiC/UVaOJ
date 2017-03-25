#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
using namespace std;

const unsigned ten[]={0,10,100,1000};
unsigned l,n;
char ans[9];

//* 0 1 2 3 4 5 6 7 8 9
inline char* Code(char *s){
	for(unsigned i=0;i<l;++i)
		if(s[i]=='*')
			s[i]=-1;
		else
			s[i]=s[i]-'0';
	return s;
}

inline bool Fill(char *a,char *b,unsigned begin,unsigned end){
	for(unsigned i=begin;i<end;++i)
		if(b[i]>=0&&a[i]!=b[i])
			return 0;
	return 1;
}

//s当前数迷 k当前要选择的位数 A筛选出的数 cur已修改数的个数 
bool DFS(char *s,unsigned k,const vector<char*> &A,unsigned cur){
	int i,j;
	char t;
	vector<char*> B;
	
	if(k+n-cur>l)
		return false;
	if(cur==n){		
		for(i=0;i<A.size();++i)
			if(Fill(A[i],s,k,l))
				B.push_back(A[i]);
		if(B.size()==1){
/*			for(i=0;i<B.size();++i){
				for(j=0;j<l;++j)
					printf("%2d",B[i][j]);
				printf("\n");
			}
			for(j=0;j<l;++j)
				if(s[j]<0)
					printf("*");
				else
					printf("%2d",s[j]);
			printf("\n");*/
			for(i=0;i<l;++i)
				ans[i]=s[i];
			return true;
		}
		return false;
	}
	unsigned next;
	t=s[k];
	for(i=-1;i<=9;++i){
		s[k]=i;
		if(i==t)
			next=cur;
		else
			next=cur+1;
		if(i==-1){
			if(DFS(s,k+1,A,next))
				return true;
		}
		else{
			B.clear();
			for(j=0;j<A.size();++j)
				if(s[k]<0||A[j][k]==s[k])
					B.push_back(A[j]);
			if(DFS(s,k+1,B,next))
				return true;
		}
	}
	s[k]=t;
	return false;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);

	char a[3],b[3],c[5],*s0,*s;
	unsigned la,lb,lc,i,j;
	vector<char*> solution;
	for(unsigned T=1;(scanf("%s%s%s",a,b,c)!=EOF)&&!(a[0]=='0'&&!a[1]);++T){
		printf("Case %u: ",T);
		
		solution.clear();
		la=strlen(a);
		lb=strlen(b);
		lc=strlen(c);
		l=la+lb+lc;
		s0=new char[l+1];
		memset(s0,0,sizeof(s0));
		sprintf(s0,"%s%s%s",a,b,c);
		
		Code(s0);
		for(i=ten[la-1];i<ten[la];++i)
			for(j=ten[lb-1];j<ten[lb];++j)
				if(ten[lc-1]<=i*j&&i*j<ten[lc]){
					s=new char[l+1];
					memset(s,0,l+1);
					sprintf(s,"%u%u%u",i,j,i*j);
					solution.push_back(Code(s));
				}

		for(n=0;!DFS(s0,0,solution,0);++n);
		
		for(i=0;i<l;++i){
			if(i==la||i==la+lb)
				printf(" ");
			if(ans[i]<0)
				printf("*");
			else
				printf("%d",ans[i]);
		}
		printf("\n");
		
		for(i=0;i<solution.size();++i)
			delete solution[i];
		delete s0;
	}
	return 0;
}

