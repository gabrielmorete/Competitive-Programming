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

int freq[500];

int cas(char a){
	if (a <= 'Z')
		return a - 'A' + 'a';
	return a - 'a' + 'A';
}

int32_t main(){
	fastio;
	string s, t;
	cin>>s>>t;

	for (auto x : t)
		freq[x]++;
	int a, b;
	a = b = 0;

	for (auto &x : s)
		if (freq[x]){
			a++;
			freq[x]--;
			x = 0;
		}
		else
			x = cas(x);

	for (auto x : s)
		if (freq[x]){
			b++;
			freq[x]--;
		}	
	cout<<a<<' '<<b<<endl;	
}