#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

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

int32_t main(){
	fastio;
	int n;
	string s, t;

	cin>>n;
	cin>>s>>t;

	if (count(all(s), '0') != count(all(t), '0')){
		cout<<-1<<endl;
		return 0;
	}

	string h;
	fr(i, n)
		if (s[i] != t[i])
			h.pb(s[i]);
	s = h;

	n = s.size();

	int z = 0, u = 0;
	
	for (int i = 0; i < n; i++){
		if (s[i] == '0'){
			if (u){
				u--;
				z++;
			}
			else
				z++;
		}
		else{
			if (z){
				u++;
				z--;
			}
			else
				u++;
		}
	}

	cout<<z + u<<endl;
}