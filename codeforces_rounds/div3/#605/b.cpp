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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const ll mod=1e9+7;

int freq[300];

void solve(){
	fill(freq, freq + 300, 0);
	string s;

	cin>>s;
	for (auto x : s)
		freq[x]++;
	int v, h;
	v = min(freq['U'], freq['D']);
	h = min(freq['L'], freq['R']);

	if (v == 0 and h != 0){
		cout<<2<<endl;
		cout<<"LR"<<endl;
		return;
	}
	if (v != 0 and h == 0){
		cout<<2<<endl;
		cout<<"UD"<<endl;
		return;
	}

	cout<<2*(v + h)<<endl;
	fr(i, v)
		cout<<'U';
	fr(i, h)
		cout<<'R';
	fr(i, v)
		cout<<'D';
	fr(i, h)
		cout<<'L';
	gnl;				

}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}