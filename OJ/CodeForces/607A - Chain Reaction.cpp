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
int memo[112345];
vii v;
vi a;

void pd(){
	fr(i, n){
		auto it = lower_bound( all(a), a[i] - v[i].snd);
		if (it == a.begin()){
			memo[i] = 1;
			continue;
		}
		else {
			int p = (int)(it - a.begin());
			p--;
			memo[i] = 1 + memo[p];
		}
	}
}

int main(){
	fastio;
	cin>>n;

	int x, y;
	fr(i,n){
		cin>>x>>y;
		v.pb({x, y});
	}

	sort(all(v));

	fr(i, n)
		a.pb( v[i].fst);
	pd();

	int bst;
	bst = 0;
	fr(i,n)
		if(memo[i] > bst){
			bst = memo[i];
	}
	cout<<n - bst<<endl;
}