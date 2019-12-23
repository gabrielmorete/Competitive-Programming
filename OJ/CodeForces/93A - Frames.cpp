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

int main(){
	fastio;
	int n,m,a,b;
	cin>>n>>m>>a>>b;

	if (m == 1 or m >= n){
		cout<<1<<endl;
		return 0;
	}

	int pa = (a - 1)/m;
	int pb = (b - 1)/m;

	if (pa == pb){
		cout<<1<<endl;
		return 0;
	}

	int ia = a%m;
	int ib = b%m;
	if (ib == 0)
		ib = m;
	if (ia == 0)
		ia = m;

	if (pb == pa + 1){
		if (ia == 1 and (ib == m or b == n))
			cout<<1<<endl;
		else
			cout<<2<<endl;
		return 0;
	}

	if (ia == ib + 1){
		cout<<2<<endl;
		return 0;
	}

	int ans = 3;
	if (ia == 1)
		ans--;
	if (ib == m or b == n)
		ans--;
	cout<<ans<<endl;
}