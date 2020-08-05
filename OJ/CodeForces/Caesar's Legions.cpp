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
const ll mod=1e8;
const int LMAXN = 25;

int n1,n2,k1,k2;
ll pdm[101][101][2];

ll pd(int a, int b, int c){
	ll &ans = pdm[a][b][c]; 
	
	if(a + b == 0) ans = 1;

	if(ans != -1) 
		return ans;

	

	ans = 0;
	if(c){
		for( int j = 1; j <= min(a,k1); j++)
			ans += pd(a-j,b,1-c);
			ans %= mod;
	}
	else{
		for( int j = 1; j <= min(b,k2); j++)
			ans += pd(a,b-j,1-c);
			ans %= mod;	
	}	

	return ans;
}

int main(){
	memset(pdm,-1,sizeof pdm);
	
	cin>>n1>>n2>>k1>>k2;

	ll aux = pd(n1,n2,0) + pd(n1,n2,1);
	aux %= mod; 
	
	cout<< aux << endl;
}