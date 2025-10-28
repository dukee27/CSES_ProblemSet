#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n , x;
    cin >> n >> x;
    vector<ll> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    
    auto subSetSum = [&](int l , int r) -> vector<ll>{
        int length = r - l + 1;
        vector<ll> res;
        for(int i = 0 ; i < (1 << length) ; i++){
            ll sum = 0;
            for(int j = 0 ; j < length ; j++){
                if(i&(1<<j)){
                    sum += arr[l+j];
                }
            }
            res.push_back(sum);
        }
        return res;
    };
   
    vector<ll> left = subSetSum(0,n/2-1);
    vector<ll> right = subSetSum(n/2 , n-1);
    sort(left.begin() , left.end());
    sort(right.begin() , right.end());
    ll ans = 0;
    for(ll i : left){
        auto low_it = lower_bound(right.begin(),right.end(),x-i);
        auto high_it = upper_bound(right.begin(),right.end(),x-i);
        ans +=  high_it - low_it;
    }
    cout << ans << endl;

}