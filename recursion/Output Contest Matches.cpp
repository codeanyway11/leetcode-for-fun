class Solution {
public:
    string getString(int n){
          stringstream ss;  
          ss<<n;  
          string s;  
          ss>>s; 
          return s;
    }
    
    string findContestMatch(int n) {
        if (n < 1) return "";
        if(n <2) return "1";
        vector<string > pairs(n+1 , "");
        for(int i=1; i<=n; i++){
            pairs[i] = getString(i);
        }
        return getValue(pairs, 1, n);    
    }
    
    string enclose(string a, string b){
        return "(" + a +"," + b + ")";
    }
 
    string getValue(vector<string> &pairs, int a, int n){
        string ans = "";
        string temp1, temp2;
        while(n >=1){
            for(int i=1; i<=n/2; i++){
                temp1= pairs[i];
                temp2 = pairs[n-i+1];
                ans = enclose(temp1, temp2);
                pairs[i] = ans;
            } 
            n = n/2;
        }
        return ans;
    }

  

};