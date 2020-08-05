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
//cout << setprecision(9)<<fixed;
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
 
const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;
 
int n;
char grid[1100][1100];
int vis[1100][1100];
ll memo[1100][1100];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
 
 
const ll MOD = (1ll<<31)-1ll;
bool valid(int i, int j){
	return i>=0 && i<n && j>=0 && j<n && grid[i][j]!='#';
}
 
ll pd(int i, int j){
 
	if(i==j && i==n-1){
		return 1;
	}
 
	ll &pdm = memo[i][j];
	if(pdm!=-1)	return pdm;
 
	pdm=0;
 
	if(valid(i+1,j))
		pdm=(pdm+pd(i+1,j))%MOD;
 
	if(valid(i,j+1))
		pdm=(pdm+pd(i,j+1))%MOD;
 
	return pdm;
 
}
 
void dfs(int i, int j){
	vis[i][j]=1;
	fr(k,4){
		int x = i + dx[k];
		int y = j + dy[k];
		if(!valid(x,y))	continue;
		if(vis[x][y])	continue;
		dfs(x,y);
	}
}
 
int main(){
 
	fastio;
	cin >> n;
	
	ms(memo,-1);
	
	fr(i,n)
		fr(j,n)
			cin >> grid[i][j];
	
	ll aux = pd(0,0);
	if(aux!=0){
		cout << aux << endl;
		return 0;
	}
 
	dfs(0,0);
 
	if(!vis[n-1][n-1])
		cout << "INCONCEIVABLE" << endl;
	else
		cout << "THE GAME IS A LIE" << endl;
 
}