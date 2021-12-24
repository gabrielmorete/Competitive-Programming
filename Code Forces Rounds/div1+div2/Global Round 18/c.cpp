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

int n;
string a, b;

void solve(){
	cin>>n;

	cin>>a>>b;

	int zra = count(all(a), '0');
	int zrb = count(all(b), '0');

	int uma = n - zra;
	int umb = n - zrb;

	if (umb != uma and umb != (zra + 1)){
		cout<<-1<<endl;
		return;
	}


	int ans = 3 * n;

	if (umb == uma){
		int aux = 0;

		fr(i, n)
			if (b[i] == '1' and a[i] == '0')
				aux++;
		ans = min(ans, 2 * aux);	
	}

	if (umb == (zra + 1)){
		int aux = 0;
		fr(i, n)
			if (b[i] == '1' and a[i] == '1')
				aux++;
		ans = min(ans, 2 * aux - 1);
	}

	cout<<ans<<endl;
}	

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;

	while (T--)
		solve();
}