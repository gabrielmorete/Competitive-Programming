#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

int n;
string guess[11];
int bull[11], cow[11];
vector<string> v;

bool valid(string &i){
	int freq[11];
	ms(freq, 0);

	for (auto x : i)
		if (freq[x - '0'] == 1){
			return false;
		}
		else
			freq[x - '0']++;

	return true;	
}

int eq(string &a, string &b){
	int ans = 0;
	fr(k, 4)
		if (a[k] == b[k])
			ans++;
	return ans;	
}

int pres(string &a, string &b){
	int freq[11];
	ms(freq, 0);
	for (auto x : a)
		freq[x - '0']++;
	int ans = 0;
	for (auto x : b)
		ans += freq[x - '0'];
	return ans;
}

bool val[10000];

int main(){
	fastio;
	cin>>n;
	int a, b;
	string s;

	fr(i, n){
		cin>>s>>a>>b;
		guess[i] = s;
		bull[i] = a;
		cow[i] = b;
	}

	for(int i = 0; i <= 9999; i++){
		s = to_string(i);
		while (s.size() < 4)
			s = "0" + s;
		if (valid(s)){
			v.pb(s);	
		}
	}

	
	int tot = 0;
	
	bool ok;	
	fr (j, v.size()){
		ok = 1;
		fr(i, n)
			if (eq(v[j], guess[i]) != bull[i] or (pres( v[j], guess[i]) - bull[i]) != cow[i])
				ok = 0;
		
		val[j] = ok;
		tot += ok;			
	}

	if (tot == 0){
		cout<<"Incorrect data"<<endl;
	}
	else if (tot > 1){
		cout<<"Need more data"<<endl;
	}
	else{
		fr(i, v.size())
			if (val[i])
				cout<<v[i]<<endl;
	}

}