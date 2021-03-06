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

int n, k, freq[26][MAXN];
string s;

void solve(){
	cin>>n>>k>>s;

	if (n % k){
		cout<<-1<<endl;
		return;
	}

	fr(j, 26)
		freq[j][0] = 0;

	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 26; j++){
			freq[j][i] = (s[i - 1] == (j + 'a'));
			freq[j][i] += freq[j][i - 1];
		}
	
	}

	bool ok = 0;
	fr(j, 26)
		if (freq[j][n] % k)
			ok = 1;
	if (ok == 0){
		cout<<s<<endl;
		return;
	}

	for (int i = n; i > 0; i--){
		freq[s[i - 1] - 'a'][i] = (freq[s[i - 1] - 'a'][i] - 1 + k) % k;

		for (int j = s[i - 1] - 'a' + 1; j < 26; j++){
			freq[j][i]++;
			int dlt = 0;

			fr(l, 26)
				dlt += (k - ((freq[l][i]) % k)) % k;

			if (dlt <= n - i and ( ((n - i) - dlt)%k == 0)){ // encontrei
				string ans = s.substr(0, i - 1);
				ans.pb(j + 'a');
				
				int sobra = (n - i) - dlt;
				while (sobra--)
					ans.pb('a');
				// agora dlt == n - i

				fr(l, 26){
					dlt = (k - ((freq[l][i]) % k)) % k;
					while (dlt--)
						ans.pb(l + 'a');
				}
				cout<<ans<<endl;
				return;
			}	

			freq[j][i]--;
		}
	}	
	cout<<-1<<endl;
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;

	while (T--)
		solve();
}