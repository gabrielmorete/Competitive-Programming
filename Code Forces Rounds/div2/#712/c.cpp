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

void solve(){
	int n;
	string s;

	cin>>n>>s;

	int zr = 0;
	fr(i, n)
		if(s[i] == '0')
			zr++;

	if (s[0] == '0' or s[n - 1] == '0' or (zr % 2)){
		cout<<"NO"<<endl;
		return;
	}

	string a, b;

	bool flip = 0;
	int abre = (n - zr)/2; // caras abrindo

	for (int i = 0; i < n; i++){
		if (s[i] == '1'){
			if (abre){
				a.pb('(');
				b.pb('(');
				abre--;
			}
			else{
				a.pb(')');
				b.pb(')');
			}
		}
		else{
			if (flip){
				a.pb(')');
				b.pb('(');
			}
			else{
				a.pb('(');
				b.pb(')');
			}
			flip = 1 - flip;
		}
	}

	cout<<"YES"<<endl;
	cout<<a<<endl;
	cout<<b<<endl;

}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}