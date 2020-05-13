#include "bits/stdc++.h"
using namespace std;

#define pb push_back
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
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const ll mod=1e9+7;

int n, h, l, r, a[2222];
int memo[2222][2222];

int good(int x){
	if (l <= x and x <= r)
		return 1;
	return 0;
}

int pd(int pos, int hour){
	if (pos == n)
		return good(hour);

	int &pdm = memo[pos][hour];
	if (pdm != -1)
		return pdm;

	if (pos == 0)
		pdm = 0;
	else
		pdm = good(hour);

	pdm += max(pd(pos + 1, (hour + a[pos])%h ), pd(pos + 1, (hour + a[pos] - 1)%h ));

	return pdm;
}


int32_t main(){
	fastio;
	cin>>n>>h>>l>>r;

	fr(i, n)
		cin>>a[i];
	
	ms(memo, -1);	
	
	cout<<pd(0, 0)<<endl;	
}