#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
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
#define rep(a, b) for (auto&(a) : (b))
#define fi get<0>
#define se get<1>
#define th get<2>
#define mp make_pair
#define mt make_tuple
#define pb push_back
ll inf = 1e18;
ll mod = 1e9 + 7;
bool compare(ll a, ll b) {return a > b;}

ll count_digits(ll n)
{
    return floor(log10(n) + 1);
}

void calc(int z)
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++) cin >> a[i];
    ll res = 0;

    for (ll i = 1; i < n; i++)
    {

        if (a[i] > a[i - 1]) continue;
        else if (a[i] == a[i - 1])
        {
            a[i] *= 10;
            res++;
            continue;
        }
        else
        {
            ll x = count_digits(a[i - 1]);
            ll y = count_digits(a[i]);
            if (x == y) {a[i] *= 10; res++;}
            else
            {
                ll ans = x - y;
                string s1 = to_string(a[i - 1]);
                string s2 = to_string(a[i]);
                if (s1[0] < s2[0])
                {
                    a[i] *= (ll)pow(10, ans);
                    res += ans;
                    continue;
                }
                ll j = 0;
                while (s1[j] == s2[j])
                {
                    j++;
                }
                if (j == 0)
                {
                    a[i] *= (ll)pow(10, ans + 1);
                    res += ans + 1;
                    continue;
                }
                x -= j;
                y -= j;
                ans = x - y;
                //cout << x << y;
                if (y == 0)
                {
                    while (s1[j] == '9' && j < s1.length() ) j++;
                    //cout << j;
                    if (j == s1.length())
                    {
                        a[i] *= (ll)pow(10, ans + 1);
                        res += ans + 1;
                    }
                    else
                    {
                        a[i] = a[i - 1] + 1;
                        res += ans;
                    }
                }
                else
                {
                    if (s2[j] > s1[j])
                    {
                        a[i] *= (ll)pow(10, ans);
                        res += ans;
                    }
                    else
                    {
                        a[i] *= (ll)pow(10, ans + 1);
                        res += ans + 1;
                    }
                }

            }
        }
    }
    //rep(x,a) cout <<x<<" ";
    cout << "Case #" << z << ": " << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int z = 1; z <= t; z++)
    {
        calc(z);
        cout << '\n';
    }

    return 0;
}
