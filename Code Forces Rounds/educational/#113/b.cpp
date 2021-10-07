#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

char ans[55][55];

void solve(){
	int n;
	string s;

	cin>>n>>s;

	vi win, draw;

	fr (i, n)
		if (s[i] == '1')
			draw.pb(i);
		else
			win.pb(i);

	if (win.size() > 0 and win.size() < 3){
		cout<<"NO"<<endl;
		return;
	}

	fr(i, n)
		fr(j, n)
			ans[i][j] = '=';
			
	int m = win.size();		
	fr(i, m){
		ans[win[i]][win[(i + 1)%m]]	= '+';
		ans[win[(i + 1)%m]][win[i]]	= '-';
	}
	
	fr(i, n)
		ans[i][i] = 'X';

	cout<<"YES"<<endl;
	fr(i, n){
		fr(j, n)
			cout<<ans[i][j];
		gnl;	
	}	
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}