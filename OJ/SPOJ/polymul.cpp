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


#define int long long int


typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;


namespace fft{
	using cd = complex<double>;
	const double PI = acos(-1);

	void fft(vector<cd> &a, bool invert) {
	    int n = a.size();
	    if (n == 1)
	        return;

	    vector<cd> a0(n / 2), a1(n / 2);
	    for (int i = 0; 2 * i < n; i++) {
	        a0[i] = a[2 * i];
	        a1[i] = a[2 * i + 1];
	    }

	    fft(a0, invert);
	    fft(a1, invert);

	    double ang = 2 * PI / n * (invert ? -1 : 1);
	    
	    cd w(1), wn(cos(ang), sin(ang));
	    for (int i = 0; 2 * i < n; i++) {
	        a[i] = a0[i] + w * a1[i];
	        a[i + n/2] = a0[i] - w * a1[i];
	        w *= wn;
	    }
	}

	vector<int> convol(vector<int> const&a, vector<int> const& b) {
	    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	    int n = 1;
	    while (n < a.size() + b.size()) 
	        n <<= 1;
	    fa.resize(n);
	    fb.resize(n);

	    fft(fa, false);
	    fft(fb, false);
	    for (int i = 0; i < n; i++)
	        fa[i] *= fb[i];
	    fft(fa, true);

	    vector<int> result(n);
	    for (int i = 0; i < n; i++){
	    	fa[i] /= n;
	        result[i] = round(fa[i].real());
	    }
	    return result;
	}
};

void solve(){
	int n;
	cin>>n;

	vi pa(n + 1), pb(n + 1);

	fr(i, n + 1)
		cin>>pa[i];
	fr(i, n + 1)
		cin>>pb[i];	

	vi pc = fft::convol(pa, pb);
	
	for (int i = 0; i <= 2*n; i++)
		cout<<pc[i]<<' ';
	gnl;
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}	