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
int n, m;
char wrd[111][111];
string s[111];

int main(){
	fastio;	
	cin>>n>>m;

	fr(i,n)
		fr(j,m)
			cin>>wrd[i][j];

	int fst = -1, ans = 1;
	
	fr(i,m){
		bool ok = 1;
		fr(j,n-1)
			if(wrd[j][i] > wrd[j + 1][i])
				ok = 0;
		if (ok){
			fst = i;
			break;
		}	
	}

	if(fst == -1){
		cout<<m<<endl;
		return 0;
	}

	fr(i,n)
		s[i].pb(wrd[i][fst]);

	
	for (int i = fst + 1; i < m; i++){
		bool ok = 1;
		fr(j, n - 1)
			if ((s[j] + wrd[j][i]) > (s[j + 1] + wrd[j + 1][i]))
				ok = 0;
		if (ok)
			fr(j, n)	
				s[j].pb(wrd[j][i]);
	}

	cout<<m - ((int)s[0].size())<<endl;



}