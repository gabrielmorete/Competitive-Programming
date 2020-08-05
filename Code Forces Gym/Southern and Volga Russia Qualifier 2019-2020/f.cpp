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


ll pd[200200][3];
ll v[200200];
int main(){
	fastio;

	int n;
	cin >> n;
	fr(i,n) cin >> v[i];

	ll ans0,ans1,ans2;
	ans0 = ans1 = ans2 = 0;
	for(int i = n-1; i>=0; i--){
		if(v[i] == 0) {
			pd[i][1] = n-i;
			pd[i][0] = pd[i][2] = 0;
		}
		else if(v[i] > 0){
			pd[i][0] = pd[i+1][0];
			pd[i][1] = pd[i+1][1];
			pd[i][2] = 1 + pd[i+1][2];
		}
		else{
			pd[i][0] = 1 + pd[i+1][2];
			pd[i][1] = pd[i+1][1];
			pd[i][2] = pd[i+1][0];
		}
		ans0 += pd[i][0];
		ans1 += pd[i][1];
		ans2 += pd[i][2];

	}
	cout << ans0 << " " << ans1 << " " << ans2 << "\n";
}