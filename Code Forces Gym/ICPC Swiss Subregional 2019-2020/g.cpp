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

bool memo[35][35][35][100][100];

int n, v[35], sum;
ll k;

pair<ll, ll> simpfy(pair<ll, ll> frc){
	ll mdc = __gcd(frc.fst, frc.snd);

	frc.fst /= mdc;
	frc.snd /= mdc;

	return frc;
}

pair<ll, ll> sfrac(pair<ll, ll> a, pair<ll, ll> b){
	pair<ll, ll> s = {a.fst * b.snd + b.fst * a.snd , a.snd * b.snd};
	return simpfy(s);
}

pair<ll, ll> getmin(pair<ll, ll> a, pair<ll, ll> b){
	if (a.fst == -1 and a.snd == -1)
		return b;
	pair<ll, ll> d1 = {abs(a.fst - k * a.snd), a.snd};
	d1 = simpfy(d1);

	pair<ll, ll> d2 = {abs(b.fst - k * b.snd), b.snd};
	d2 = simpfy(d2);

	if (d1.fst * d2.snd < d2.fst * d1.snd)
		return a;
	if (d1.fst * d2.snd > d2.fst * d1.snd)
		return b;

	if (a.fst * b.snd <= b.fst * a.snd)
		return a;
	return b;
}


pair<ll, ll> pd(){
	memo[0][0][0][0][0] = 1;

	for (int pos = 1; pos <= n; pos++)
		for (int sa = 0; sa < n; sa++)
			for (int sb = 0; sb < n; sb++)
				for (int suma = 0; suma < sum; suma++)
					for (int sumb = 0; sumb < sum; sumb++)
						if (sa + sb < n and suma + sumb < sum){
							bool &pdm = memo[pos][sa][sb][suma][sumb];
							pdm = 0;
							if (sa > 0 and suma >= v[pos])
								pdm |= memo[pos - 1][sa - 1][sb][suma - v[pos]][sumb];
							if (sb > 0 and sumb >= v[pos])
								pdm |= memo[pos - 1][sa][sb - 1][suma][sumb - v[pos]];
							pdm |= memo[pos - 1][sa][sb][suma][sumb];
						}

	pair<ll, ll> ans = {-1, -1}, fa, fb, fc;					

	for (int sa = 1; sa < n; sa++)
			for (int sb = 1; sb < n; sb++)
				for (int suma = 1; suma < sum; suma++)
					for (int sumb = 1; sumb < sum; sumb++)
						if (memo[n][sa][sb][suma][sumb]){
							fa = {suma, sa};
							fb = {sumb, sb};
							fc = {sum - (suma + sumb), n - (sa + sb)};

							fa = sfrac(fa, fb);
							fa = sfrac(fa, fc);
							
							fa.snd *= 3;
							fa = simpfy(fa);
							
							ans = getmin(ans, fa);
						}
							
	return ans;					
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin>>n>>k;
	
	frr(i, n){
		cin>>v[i];
		sum += v[i];
	}

	pair<ll, ll> ans = pd();

	cout<<ans.fst<<'/'<<ans.snd<<endl;
}