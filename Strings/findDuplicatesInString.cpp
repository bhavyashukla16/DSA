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