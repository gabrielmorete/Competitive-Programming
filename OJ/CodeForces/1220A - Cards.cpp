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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

int freq[2323];

int main(){
	fastio;
	int n;
	string s;
	cin>>n;
	cin>>s;
	for(auto x : s)
		freq[x]++;
	
	int one = min(freq['o'],min(freq['n'],freq['e']));
	freq['o']-=one;
	freq['n']-=one;
	freq['e']-=one;	

	int zero = min(freq['z'],min(freq['e'],min(freq['r'],freq['o'])));
	fr(i,one)
		cout<<1<<' ';
	fr(i,zero)
		cout<<0<<' ';
	if(one or zero)
	gnl;		
}