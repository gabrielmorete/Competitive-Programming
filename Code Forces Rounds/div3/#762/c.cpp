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

void solve(){
	string a, s;
	cin>>a>>s;

	reverse(all(a));
	reverse(all(s));

	int n = a.size();

	while (a.size() < s.size())
		a.pb('0'); // leading zeros

	int p = 0;

	string b;

	for (int i = 0; i < a.size(); i++){
		if (p >= s.size()){
			if (i >= n)
				goto here;
							
			cout<<"-1"<<endl;
			return;
		}
		
		if (a[i] <= s[p]){
			char f = s[p] - a[i] + '0';
			b.pb(f);
			p++;
		}
		else{
			if (p + 1 == s.size() or s[p + 1] != '1'){
				cout<<"-1"<<endl;
				return;
			}
			int x = 10 + (s[p] - '0');
			int y = a[i] - '0';
			int z = x - y;
			b.pb(z + '0');
			p += 2;
		}
	}

	here:

	while (!b.empty() and b.back() == '0')
		b.pop_back();

	reverse(all(b));
	cout<<b<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}