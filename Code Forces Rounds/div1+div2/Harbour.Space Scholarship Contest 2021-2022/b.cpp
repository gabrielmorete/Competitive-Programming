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

string s, t;
int n, m;


bool test(int p, int q){
	q++;
	p--;
	if (m - q > p + 1) 
		return false;

	while (q < m){
		if (s[p] != t[q])
			return false;
		q++;
		p--;
	}

	return true;
}

void solve(){
	cin>>s>>t;

	n = s.size();
	m = t.size();

	for (int i = 0; i < n; i++){
		int p = i;
		int q = 0;
		while (p < n and q < m and s[p] == t[q]){
			if (test(p, q)){
				cout<<"yes"<<endl;
				return;
			}
			p++;
			q++;
		}
		
		if (q == m){
			cout<<"yes"<<endl;
			return;
		}
	}

	cout<<"no"<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}