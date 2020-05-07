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

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int v[412345], vv[412345];
	bool foi = 0;

	int a;
	fr(i, n){
		a = s[i] - '0';
		if (a == 2){
			if (foi){
				vv[i] = 2;
				v[i] = 0;
			}
			else{
				vv[i] = 1;
				v[i] = 1;
			}

		}
		else if (a == 0){
			v[i] = vv[i] = 0;
		}
		else{
			if (foi){
				vv[i] = 1;
				v[i] = 0;
			}
			else{
				v[i] = 1;
				vv[i] = 0;
				foi = 1;
			}				
		}
	}
	fr(i, n)
		cout<<v[i];
	gnl;
	fr(i, n)
		cout<<vv[i];
	gnl;		

	
}

int main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}