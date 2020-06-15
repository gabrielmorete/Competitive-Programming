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

int d1[MAXN], d2[MAXN];	// d1[i] # de palindromos impares centrados em i
int pal[2 * MAXN];		// d2[i] # de palindromos pares centrados em i (aab[b]aa) 
						// pal[2i] maior palindromo centrado em i
						// pal[2i + 1] maior palindromo centrado em i e i + 1
void manacher(string &s){
	int tam = s.size();
	for (int i = 0, l = 0, r = -1; i < tam; i++){
		int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    	while (0 <= i - k and i + k < tam and s[i - k] == s[i + k]) {
    	    k++;
    	}
    	d1[i] = k--;
    	if (i + k > r) {
    	    l = i - k;
		    r = i + k;
		}
	}

	for (int i = 0, l = 0, r = -1; i < tam; i++) {
	    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
	    while (0 <= i - k - 1 and i + k < tam and s[i - k - 1] == s[i + k]) {
	        k++;
	    }
	    d2[i] = k--;
	    if (i + k > r) {
	        l = i - k - 1;
    		r = i + k ;
    	}
	}

	for (int i = 0; i < tam; i++)
		pal[2 * i] = 2 * d1[i] - 1;
	for (int i = 0; i < tam - 1; i++)
		pal[2 * i + 1] = 2 * d2[i + 1];
}

int32_t main(){
	fastio;

	int n;
	string s;
	
	cin>>n;
	cin>>s;

	manacher(s);
	int ans = 1;
	fr(i, n)
		ans = max({ans, pal[2 * i], pal[2 * i + 1]});

	cout<<ans<<endl;	
}