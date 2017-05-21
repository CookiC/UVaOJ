#include<iostream>
#include<string>
#include<cstring>
using namespace std;

string S,T;
unsigned C,i,j;
int sum;
int cnt[4];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	cin>>C;
	for(i=0;i<C;++i){
		memset(cnt,0,sizeof(cnt));

		cin>>S>>T;
		for(j=0;j<S.size();++j)
			if(S[j]!=T[j])
				switch(S[j]){
					case '?':++cnt[T[j]-'0'];break;
					case '1':++cnt[2];break;
					case '0':++cnt[3];
				}
		cout<<"Case "<<i+1<<": ";
		if(cnt[2]>cnt[3]+cnt[1])
			cout<<-1<<endl;
		else
			cout<<(cnt[2]>cnt[3]?cnt[0]+cnt[1]+cnt[2]:cnt[0]+cnt[1]+cnt[3])<<endl;
	}
	return 0;
}

