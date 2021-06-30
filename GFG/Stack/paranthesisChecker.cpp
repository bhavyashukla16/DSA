//https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1#

//TC=O(|x|) SC=O(|x|)
//Function to check if brackets are balanced or not.
bool ispar(string x)
    {
        // Your code here
        stack<char> s;
        for(int i=0;i<x.length();i++)
        {
            if(x[i]=='[' || x[i]=='{' || x[i]=='(')
            s.push(x[i]);
            else
            {
                if(s.empty())
                return false;
                
                switch(x[i]) {
                    case ')':
                        if(s.top()!='(')
                        return false;
                        else s.pop();
                        break;
                    case '}':
                        if(s.top()!='{')
                        return false;
                        else s.pop();
                        break;
                    case ']':
                        if(s.top()!='[')
                        return false;
                        else s.pop();
                        break;
                }
            }
        }
        return s.empty();
    }