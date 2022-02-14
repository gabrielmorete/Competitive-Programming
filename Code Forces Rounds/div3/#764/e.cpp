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
const int MAXN = 4e5 + 10;

map<string, pii> crd;
int n, m;
string in[MAXN], s;

bool memo[MAXN][2];

void solve(){
	crd.clear();

	cin>>n>>m;
	fr(i, n)
		cin>>in[i];

	cin>>s;

	if (m == 1){
		cout<<-1<<endl;
		return;
	}
	if (m == 2){
		fr(i, n)
			if (in[i] == s){
				cout<<1<<endl;
				cout<<"1 2 "<<i + 1<<endl;
				return;
			}
		cout<<-1<<endl;
		return;	
	}

	fr(i, n){
		for (int j = 0; j + 1 < m; j++){
			string t = in[i].substr(j, 2);
			crd[t] = {i, j};
		}
	}

	fr(i, n){
		for (int j = 0; j + 2 < m; j++){
			string t = in[i].substr(j, 3);
			crd[t] = {i, j};
		}
	}

	fr(i, m + 5)
		fr(j, 2)
			memo[i][j] = 0;


	memo[m][0] = memo[m][1] = 1; // can do zero
	
	string aux = s.substr(m - 2, 2);
	if (crd.count(aux))
		memo[m - 2][0] = 1; // I can

	for (int i = m - 3; i >= 0; i--){
		aux = s.substr(i, 2);
		if (crd.count(aux))
			memo[i][0] = memo[i + 2][0] or memo[i + 2][1];
	
		aux = s.substr(i, 3);
		if (crd.count(aux))
			memo[i][1] = memo[i + 3][0] or memo[i + 3][1];
	}

	if (memo[0][0] == 0 and memo[0][1] == 0){
		cout<<-1<<endl;
		return;
	}

	int p = 0;

	vector<array<int, 3>> ans;

	while (p < m){
		if (memo[p][0]){
			string t = s.substr(p, 2);
			int l, id;
			tie(id, l) = crd[t];
			ans.pb({l + 1, l + 2, id + 1});
			p = p + 2;
		}
		else{
			string t = s.substr(p, 3);
			int l, id;
			tie(id, l) = crd[t];
			ans.pb({l + 1, l + 3, id + 1});
			p = p + 3;
		}
	}

	cout<<ans.size()<<endl;
	for (auto x : ans)
		cout<<x[0]<<' '<<x[1]<<' '<<x[2]<<endl;
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}