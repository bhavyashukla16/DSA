// METHOD 1: Set
void findDuplicates( string s, int n ) {

    set<char> st;
    for(int i=0;i<n;i++)
    {
        if(st.find(s[i])==st.end())
        st.insert(s[i]);

        else
        cout<<s[i]<<" ";
    }

}
// METHOD 2: hash map
void removeDuplicates( string s, int n ) {

    map<int, bool> mp;
    string ans="";

    for(int i=0;i<n;i++)
    {
        if(mp[s[i]]==false)
        {
            mp[s[i]]=true;
            ans+=s[i];
        }
    }
    cout<<ans;
}