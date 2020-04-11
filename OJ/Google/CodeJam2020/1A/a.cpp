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

string in[100], esq[100], dir[100], mid[100];


void solve(){
	int n;
	cin>>n;
	fr(i,n)
		cin>>in[i];
	
	string s;
	fr(i, n){
		esq[i].clear();
		dir[i].clear();
		mid[i].clear();
		s = in[i];

		fr(j, s.size()){
			if (s[j] == '*')
				break;
			esq[i].pb(s[j]);
		}


		for (int j = s.size() - 1; j >= 0; j--){
			if (s[j] == '*')
				break;
			dir[i].pb(s[j]);
		}

		int h = 0;
		for (auto f : s)
			if (f == '*')
				h++;
	
		if (h > 1){
			int pos = 0;
			while (s[pos] != '*')
				pos++;
			pos++;
			h--;

			while (h > 0){
				if (s[pos] != '*')
					mid[i].pb(s[pos]);
				else
					h--;
				pos++;
			}
		}
	}

	sort(esq, esq + n);
	sort(dir, dir + n);


	set<char> q;
	bool ok = 1;
		fr(i, 110){
		q.clear();
		fr(j, n){
			if (i < esq[j].size())
				q.insert({esq[j][i]});
		}
		if (q.size() > 1)
			ok = 0;
	}

	fr(i, 110){
		q.clear();
		fr(j, n){
			if (i < dir[j].size())
				q.insert({dir[j][i]});
		}
		if (q.size() > 1)
			ok = 0;
	}

	if (ok == 0){
		cout<<'*'<<endl;
	}
	else{
		string ans;
		ans = esq[n - 1];
		fr(i, n)
			ans += mid[i];
		reverse(all(dir[n - 1]));	
		ans += dir[n - 1];	
		cout<<ans<<endl;
	}

}

int main(){
	fastio;
	int t;
	cin>>t;
	frr(i,t){
		cout<<"Case #"<<i<<": ";
		solve();
	}
}