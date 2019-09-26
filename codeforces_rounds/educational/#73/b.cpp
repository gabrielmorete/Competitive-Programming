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
const ll llINF = (long long)(1e18) + 100;  
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

int m[123][123];

int main(){
	fastio;

	cin>>n;

	bool col;
	col = 0;
	fr(i,n){
		m[0][i] = (1-col);
		col = 1 - col;
		}
	frr(i,n-1)
		fr(j,n)
			m[i][j] = 1-m[i-1][j];	


	fr(i,n){
		fr(j,n)
			cout<<(m[i][j]?"B" : "W");
	gnl;		
	}	
	dbg(llINF);




}