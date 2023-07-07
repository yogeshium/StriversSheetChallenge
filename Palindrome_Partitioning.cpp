//My Approach (First time thought) :
bool checkPalindrome(string& s, int i, int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;j--;
        }
        return true;
    }
    bool check(string s, vector<int>& p)
    {
        int i=0,j;
        for(int j=0;j<p.size();j++)
        {
            if(!checkPalindrome(s,i,p[j]))
                return false;
            i=p[j]+1;
        }
        if(i<s.size())
            if(!checkPalindrome(s,i,s.size()-1))
                return false;
        return true;
    }

    vector<string> make(string& s, vector<int>& p)
    {
        int i=0;
        vector<string> ans;
        for(int j=0;j<p.size();j++)
        {
            ans.push_back(s.substr(i,p[j]-i+1));
            i=p[j]+1;
        }
        if(i<s.size())
            ans.push_back(s.substr(i,s.size()-i));
        return ans;
    }

    void solve(string s, int i, vector<int> p, vector<vector<string>>& ans)
    {
        if(i==s.size()-1)
        {
            // cout<<"partition: ";
            // for(int j=0;j<p.size();j++)
            //     cout<<p[j]<<" ";
            // cout<<endl;

            if(check(s,p))
            {
                ans.push_back(make(s,p));
            }
            return;    
        }
       
        //Not take
        solve(s,i+1,p,ans);

        //take
        p.push_back(i);
        solve(s,i+1,p,ans);
    }

    vector<vector<string>> partition(string s) 
    {
        vector<int> p;
        vector<vector<string>> ans;
        solve(s,0,p,ans);

        return ans;   
    }



//Better Approach (Seen Striver video)
 bool checkPalindrome(string& s, int j)
    {
        int i=0;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;j--;
        }
        return true;
    }

    void solve(string s,vector<string> temp, vector<vector<string>>& ans)
    {
        if(s.size()==0)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<s.size();i++)
        {
            if(checkPalindrome(s,i))
            {
                temp.push_back(s.substr(0,i+1));
                if(i+1<s.size())
                    solve(s.substr(i+1),temp, ans);
                else
                    solve("",temp,ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,temp,ans);

        return ans;    
    }
