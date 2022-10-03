#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define ffst                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define m 1000000007
// by sudhnsh
bool comp(pair<ll, char> v1, pair<ll, char> v2)
{
    return v1.first<v2.first;
}
void solve()
{
    ll n;
    cin>>n;
    vector<ll> v2(n);
    vector<pair<ll,char>> v1,temp1,temp2;
    rep(i,0,n)
    {
        cin>>v2[i];
    }
    string s;
    cin>>s;
    vector<ll> v3,v4;
    v3=v2;
    v4=v3;
    rep(i,0,n)
    {
        v1.push_back(make_pair(v2[i],s[i]));
    }
    sort(v2.begin(),v2.end());
    rep(i,0,n)
    {
        if(v2[i]!=v1[i].first)
        {   
            break;
        }
        if(i==n-1)
        {
            cout<<0<<'\n';
            return;
        }
    }
    rep(i,0,n-1)
    {
        if(s[i]!=s[i+1])
        {
            break;
        }
        if(i+1==n-1)
        {
            cout<<-1<<'\n';
            return;
        }
    }
    ll fn=n-1,fs=n-1,ls=0,ln=0;
    rep(i,0,n)
    {
        if(v1[i].second=='N')
        {
            fn=min(fn,i);
            ln=max(ln,i);
        }
        else
        {
            fs=min(fs,i);
            ls=max(ls,i);
        }
    }
    sort(v3.begin()+fn,v3.begin()+ls+1);
   // cout<<fs<<' '<<ln<<'\n';

    rep(i, 0, n)
    {
        if (v2[i] != v3[i])
        {
            break;
        }
        if (i == n - 1)
        {
            cout << 1 << '\n';
            return;
        }
    }
    sort(v4.begin() + fs, v4.begin() + ln+1);
    rep(i, 0, n)
    {
        if (v2[i] != v4[i])
        {
            break;
        }
        if (i == n - 1)
        {
            cout << 1 << '\n';
            return;
        }
    }
    cout<<2<<'\n';
    return;
}
int main()
{
    ffst;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}