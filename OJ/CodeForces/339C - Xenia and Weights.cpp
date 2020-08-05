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
bool av[11];
int m;

typedef tuple<int,int,int> tup;
map<tup, int> vis;

bool dfs(int df, int lst, int stp) {
	vis[{df, lst, stp}] = 1;
	if (stp > m)
		return true;
	
	frr(i, 10)
		if (av[i] and i != lst) 	{
			if (stp % 2 and df + i > 0) {
				if (!vis[{df + i, i, stp + 1}] and dfs( df + i, i, stp + 1)){
					vis[{df, lst, stp}] = i;
					return true;
				}
			}
			else if( !(stp % 2) and df - i < 0) {
				if (!vis[{df - i, i, stp + 1}] and dfs( df - i, i, stp + 1)){
					vis[{df, lst, stp}] = i;
					return true;
				}
			}
		}	
	return false;
}

int main(){
	fastio;
	int n;
	cin>>n>>m;
	int cnt = 1;
	while (n > 0){
		if (n % 10)
			av[cnt] = 1;
		cnt++;
		n /= 10;
	}
	reverse(av + 1, av + 11);
	
	if(!dfs(0,0,1)){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	int a, b, c, d;
	a = b = 0;
	c = 1;
	while (m--) {
		d = vis[{a, b, c}];
		cout<<d<<' ';
		if (a > 0)
			a -= d;
		else
			a += d;
		b = d;
		c++;
	}
	gnl;

	
}