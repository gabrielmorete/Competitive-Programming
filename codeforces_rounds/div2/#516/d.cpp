#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;

int memo[2123][2123];
char tab[2123][2123];
int n,m;

bool in(int x,int y){
	if(x<1 || y<1 || x>m || y>n)
		return 0; 
	return 1;
}

int dfs(int a,int b,int X,int Y,bool lft,int down){
	if(in(a,b)==0 || tab[a][b]=='*')
		return 0;
	int r=0;
	
	if(lft =-1){
		if(X>0)
			r+=dfs(a+1,b,X-1,Y,0,-1);
		if(Y>0)
			r+=dfs(a-1,b,X,Y-1,1,-1);
	}
	else if(lft==0){
		if(X>0)
			r+=dfs(a+1,b,X-1,Y,0,-1);
	}
	else if(Y>0)
		r+=dfs(a-1,b,X,Y-1,1,-1);
	
	if(down==-1){	
		r+=dfs(a,b+1,X,Y,-1,0);
		r+=dfs(a,b-1,X,Y,-1,1);
	}
	else if(down ==1)	
		r+=dfs(a,b-1,X,Y,-1,1);
	else
		r+=dfs(a,b+1,X,Y,-1,0);
	
	if(memo[a][b]==0){
		memo[a][b]=1;
		r++;
	}
	return r;
}

int main(){
	fastio; 
	int r,c,x,y; 
	cin>>n>>m>>r>>c>>x>>y; 
	char k; 
	frr(i,n){
		frr(j,m){
			cin>>k;
			tab[i][j]=k;
		}
	}	
	cout<<dfs(r,c,y,x,-1,-1)<<endl;
}