#include<bits/stdc++.h>

using namespace std; 

unordered_map <string,string> db;

string key_str (string s, int n){
    string ans = "";
    for (char c : s){
        if (n%2) ans += c;
        n >>= 1;
    }
    return ans;
}

string solve (string &s){
    int n = 1 << 9;
    int best = 0;
    string bests = "IMPOSSIBLE"; 
    while (--n) {
        string num = key_str(s,n);
        sort(num.begin(), num.end());
        if (db.find(num) != db.end()) {
            // cout << num << endl;
            string st = db[num];
            if (st.size() > best || (st.size() == best && st < bests)) {
                best = st.size();
                bests = st;
            }
        }
    }

    return bests;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    while(N--) {
        string s, or_s; 
        cin >> s; or_s = s;
        sort(or_s.begin(),or_s.end());
        if (db.find(or_s) != db.end())
            db[or_s] = min(s, db[or_s]);
        else
            db[or_s] = s;
    }

    int q; 
    cin >> q;
    
    while(q--){
        string s;
        cin >> s;
        cout << solve(s) << '\n';
    }
    return 0;
}