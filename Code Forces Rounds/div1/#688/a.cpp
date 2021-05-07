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

int n, k;
string s;

void solve(){
	cin>>n>>k;
	cin>>s;

	bool ok = 1;
	for (int i = 0; i < n; i++){
		if (s[i] != '?' and i + k < n){
			if (s[i] != s[i + k] and s[i + k] != '?')
				ok = 0;
			s[i + k] = s[i];
		}
	}

	reverse(all(s));
	for (int i = 0; i < n; i++){
		if (s[i] != '?' and i + k < n){
			if (s[i] != s[i + k] and s[i + k] != '?')
				ok = 0;
			s[i + k] = s[i];
		}
	}
	reverse(all(s));

	int z, u;
	z = u = 0;

	fr(i, k){
		if (s[i] == '0')
			z++;
		if (s[i] == '1')
			u++;
	}

	fr(i, k){
		if (s[i] == '?'){
			if (z > u){
				for (int j = i; j < n; j += k)
					s[j] = '1';
				u++;
			}
			else{
				for (int j = i; j < n; j += k)
					s[j] = '0';
				z++;
			}
		}
	}

	if (z != u)
		ok = 0;

	if (ok)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}