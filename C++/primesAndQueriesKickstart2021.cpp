#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vs = vector<string>;
using mi = map<int, int>;
using ml = map<ll, ll>;
using umi = unordered_map<int, int>;
using uml = unordered_map<ll, ll>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using ti = tuple<int, int, int>;
using tl = tuple<ll, ll, ll>;
using vii = vector<pi>;
using viii = vector<ti>;
using vll = vector<pl>;
using vlll = vector<tl>;
using pq = priority_queue <ll, vl, greater<ll>>;
using gq = priority_queue <ll>;
#define mem(dp) memset(dp, -1, sizeof(dp))
#define aut(a, b) for (auto&(a) : (b))
#define out(x, v) for (auto&(x) : (v)) cout << x << " "; cout << '\n';
#define rep(i, n) for (ll (i) = 0; (i) < (n); ++(i) )
#define repp(i, n) for (ll (i) = 1; (i) <= (n); ++(i) )
#define all(v) v.begin(), v.end()
#define fi get<0>
#define se get<1>
#define th get<2>
#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define pb push_back
ll inf = 1e18;
ll mod = 1e9 + 7;
bool compare(ll a, ll b) {return a > b;}
ll gcd(ll a , ll b) {if (b == 0) return a; a %= b; return gcd(b, a);}
ll digit(ll n) {return floor(log10(n) + 1);}

ll generatePrimeFactors(ll n, ll p)
{
    // return 0;
    ll arr[n + 1];

    vector <bool> prime(n + 1, false);

    for (ll i = 2; i <= n; i += 2)
        arr[i] = 2;

    for (ll i = 3; i <= n; i += 2)
    {
        if (prime[i] == false)
        {
            arr[i] = i;

            for (ll j = i; j * i <= n; j += 2)
            {
                if (prime[i * j] == false)
                {
                    prime[i * j] = true;

                    arr[i * j] = i;
                }
            }
        }
    }

    ll curr = arr[n];
    ll cnt = 1;

    while (n > 1)
    {
        n /= arr[n];

        if (curr == arr[n])
        {
            cnt++;
            continue;
        }

        if (curr == p) return cnt;

        curr = arr[n];
        cnt = 1;
    }
    return 0;
}

void calc()
{
    ll n, q, p;
    cin >> n >> q >> p;
    ll a[n];
    rep(i, n) cin >> a[i];
    while (q--)
    {
        int tt;
        cin >> tt;
        if (tt == 1)
        {
            ll x, b;
            cin >> x >> b;
            a[x - 1] = b;
        }
        else
        {
            ll s, l, r, res = 0;
            cin >> s >> l >> r;
            for (ll i = l; i <= r; i++)
            {
                ll x = (ll)pow(a[i - 1], s);
                ll y = a[i - 1] % p;
                y = (ll)pow(y, s);
                ll z = x + y;
                if (z == 0) continue;
                res += generatePrimeFactors(z, p);
            }
            cout << res << " ";
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    repp(z, t)
    {
        cout << "Case #" << z << ": ";
        calc();
        cout << '\n';
    }

    return 0;
}
