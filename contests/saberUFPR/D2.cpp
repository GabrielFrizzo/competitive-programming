void ins (char s[], vector <vi> &trie, vi &leaf){
    int u=0;
    for (int i = 0; s[i]; i++){
        if (trie[u][s[i]-'a']==-1){
            trie[u][s[i]-'a'] = trie.size();
            trie.push_back(vi(26,-1));
            leaf.pushback(0);
        }
        u = trie[u][s[i]-'a'];
    }
    leaf[u]=1;
}
void solve(){
  int n; char str[112];
  while(scanf("%d",&n)!=EOF){
      vector <vi> trie; vi leaf;
      trie.assign(1,vi(26,-1));leaf.assign(1,0);
      while (n--) ins (str,trie,leaf);
  }
}
