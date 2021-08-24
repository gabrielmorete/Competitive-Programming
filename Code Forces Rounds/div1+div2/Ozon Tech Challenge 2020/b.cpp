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

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;

	cin>>s;

	if (s.size() == 1){
		cout<<0<<endl;
		return 0;
	}


	bool ok = 0;

	stack<int> stk;

	int n = s.size();

	vi abre, fecha;

	fr(i, n)
		if (s[i] == '(')
			abre.pb(i + 1);
		else
			fecha.pb(i + 1);

		vi ans;
	reverse(all(abre));
	
	while (!abre.empty() and !fecha.empty()){
		if (abre.back() > fecha.back())
			break;
		ans.pb(abre.back());
		ans.pb(fecha.back());
		abre.pop_back();
		fecha.pop_back();
	}

	sort(all(ans));

	if (ans.size() == 0){
		cout<<0<<endl;
	}
	else{
		cout<<1<<endl;
		cout<<ans.size()<<endl;
		for (auto x : ans)
			cout<<x<<' ';
		gnl;
	}

}