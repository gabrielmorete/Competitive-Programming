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

char mapa[555][555];
bool vis[555][555];
int n,m,k;

bool valid(int x, int y){
	if(x < 0 or y < 0) return 0;
	if(x >= n or y >= m) return 0;
	if(mapa[x][y] == '#') return 0;
	return 1;
}

int mx[4]={0,1,0,-1};
int my[4]={1,0,-1,0};

void dfs(int x, int y){
	vis[x][y] = 1;

	fr(i,4)
		if(valid(x+mx[i],y+my[i]) and vis[x+mx[i]][y+my[i]] == 0)
			dfs(x+mx[i],y+my[i]);
	if(k){
		mapa[x][y] = 'X';
		k--;	
	}

}


int main(){
	fastio;

	cin>>n>>m>>k;
	
	string s;
	fr(i,n){
		cin>>s;
		fr(j,m)
			mapa[i][j] = s[j];
	}

	fr(i,n)
		fr(j,m)
			if(mapa[i][j] == '.'){
				dfs(i,j);
				break;
			}


	fr(i,n){
		fr(j,m)
			cout<<mapa[i][j];
		gnl;	
	}

		
}