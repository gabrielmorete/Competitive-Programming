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
string s;
ll a, b, aa[1123456], bb[1123456];

ll fastxp( ll base, ll exp) {
	ll ans = 1;
	while(exp > 0){
		if(exp % 2)
			ans = ans*base % b;
		base = base*base % b;
		exp /=2;
	}
	return ans;
}

int main(){
	fastio;
	
	cin>>s>>a>>b;


	aa[0] = (s[0] - '0') % a;
	frr(i,s.size() - 1)
		aa[i] = (aa[i-1]*10 + (s[i] - '0')) % a;

	bb[s.size()-1] = (s[s.size()-1] - '0') % b;	
	for(int i = s.size() - 2; i >= 0; i--){
		bb[i] = (bb[i+1] + (s[i] - '0')*fastxp(10, (s.size()) - i - 1)) % b;
	}

	int l = -1, r = -1;
	fr(i,s.size())
		if (s[i] != '0') {
			l = i;
			break;
		}
	fr(i,s.size())
		if (s[i] != '0')
			r = i;

	if (l == -1 or l == r){
		cout<<"NO"<<endl;
		return 0;
	}


	for (int i = l; i < r; i++){
		if (aa[i] == 0 and bb[i + 1] == 0) {
			while (s[i + 1] == '0')
				i++;
			cout<<"YES"<<endl;
			int j;
			for (int j = 0; j <= i or s[j] == '0'; j++)
				cout<<s[j];
			gnl;
			for (int j = i + 1; j < s.size(); j++)
				cout<<s[j];
			gnl;
			return 0;		
		}
	}
	cout<<"NO"<<endl;



}