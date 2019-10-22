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
	int m, s;

	cin>>m>>s;

	if (s == 0 and m > 1 or m * 9 < s){
		cout<<-1<<' '<<-1<<endl;
		return 0;
	}
	else if (s == 0 and m == 1){
		cout<<0<<' '<<0<<endl;
		return 0;
	}
	int ss;

	ss = s;
	string t;
	fr (i,m){
		if (ss == 1 and i != m - 1)
			t.pb('0');
		else if (ss <= 9 and i != m - 1) {
			t.pb(ss - 1 + '0');
			ss = 1;
		}
		else if (ss > 9 and i != m - 1) {
			t.pb('9');
			ss -= 9;
		}
		else
			t.pb(ss + '0');
	}
	reverse( all(t));
	cout<<t;

	cout<<' ';

	ss = s;
	fr (i,m){
		cout<<min(9, ss);
		ss -= min(9,ss);
	}

	gnl;

}