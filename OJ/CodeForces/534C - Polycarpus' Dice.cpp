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
ll n, a, d[212345], sum, b[212345];

int main(){
	fastio;
	cin>>n>>a;

	fr(i,n){
		cin>>d[i];
		sum += d[i];
	}

	fr(i,n){
		if ((a - n + 1) < d[i])
			b[i] += d[i] - a + n - 1;
		
		if ((a - sum + d[i]) > 0)
			b[i] += (a - sum + d[i]) - 1;
	}
	fr(i,n)
		cout<<b[i]<<' ';
	gnl;	
}