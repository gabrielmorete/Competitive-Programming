#include "bits/stdc++.h"
using namespace std;

#define pb push_back
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
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const ll mod=1e9+7;

vii com;

pii move(char c){
	if (c == 'U'){
		return {0, + 1};
	}else if (c == 'D'){
		return {0, -1};
	}else if (c == 'L'){
		return {-1, 0};
	}else{
		return {1, 0};
	}

	return {0, 0};
}

void solve(){
	com.clear();
	int n;
	string s;

	cin>>n>>s;
	com.pb({0, 0});
	for (auto x : s){
		pii aux = move(x);
		pii aux2 = com[com.size() - 1];
		com.pb({aux.fst + aux2.fst, aux.snd + aux2.snd});
	}

	int ans = n + 100, l, r;

	map<pii, int> pos;


	fr(i, n + 1){
		if (!pos.count(com[i]))
			pos[com[i]] = i + 1;
		else if (ans > i + 1 - pos[com[i]]){
			ans = i - pos[com[i]] + 1;
			l = pos[com[i]];
			r = i;
		}
		pos[com[i]] = i + 1;
	}

	if (ans == n + 100){
		cout<<-1<<endl;
	}
	else
		cout<<l<<' '<<r<<endl;

}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}