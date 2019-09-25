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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

ll m[1123][1123];

int main(){
	fastio;
	int n;
	cin>>n;

	frr(i,n){
		frr(j,n)
			cin>>m[i][j];
	}

	vll ans;
	ll aux;
	aux = m[1][2]*m[1][3]/m[2][3];
	cout<<(ll)sqrt(aux)<<' ';

	aux = m[2][1]*m[2][3]/m[1][3];
	cout<<(ll)sqrt(aux)<<' ';

	for(int i = 3; i <= n; i++){
		aux = m[i][1]*m[i][2]/m[1][2];
		cout<<(ll)sqrt(aux)<<' ';
	}
	gnl;



}