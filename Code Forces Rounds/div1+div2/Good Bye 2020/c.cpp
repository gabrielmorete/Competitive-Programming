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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

int n;
string s;

void solve(){
	cin>>s;
	n = s.size();

	if (n == 1){
		cout<<0<<endl;
		return;
	}

	if (n == 2){
		cout<<(s[0] == s[1])<<endl;
		return;
	}

	int ans = 0;
	map<char, int> freq;

	// caso de contorno, ponta esquerda;
	if (s[1] == s[0]){
		freq.clear();
		for (int i = 1; i < min(n, 4); i++)
			freq[s[i]] = 1;

		for (char a = 'a'; a <= 'z'; a++)
			if (freq[a] == 0){
				s[1] = a;
				ans++;
				break;
			}
	}

	for (int i = 2; i < n; i++){
		if (s[i - 1] != s[i] and s[i - 2] != s[i])
			continue;
		
		freq.clear();

		for (int j = i - 2; j < min(n, i + 3); j++)
			freq[s[j]] = 1;

		for (char a = 'a'; a <= 'z'; a++)
			if (freq[a] == 0){
				s[i] = a;
				ans++;
				break;
			}
	}

	cout<<ans<<endl;
}



int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T;

	cin>>T;

	while (T--)
		solve();
}