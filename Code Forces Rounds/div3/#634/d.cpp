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

int m[10][10];

void solve(){
	ll in;
	fr(i, 9){
		cin>>in;
		fr(j, 9){
			m[i][9 - j - 1] = in%10ll;
			in /= 10ll;
		}
	}
	int x[9] = {0, 3, 6, 1, 4, 7, 2, 5, 8};
	int y[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};


	fr(i, 9){
		frr(j, 9)
			if (m[x[i]][y[i]] != j){
				m[x[i]][y[i]] = j;
				break;
			}
	}
	fr(i, 9){
		fr(j, 9)
			cout<<m[i][j];
		gnl;
	}
				
}

int main(){
	fastio;
	int t;
	cin>>t;
	while (t--)
		solve();
}