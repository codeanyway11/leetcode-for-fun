class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size() || num.size()<1){
            return "0";
        }
        
        stack<char> stack;
        for(int i=0; i<num.size(); i++){
            while(k>0 && !stack.empty() && stack.top()-'0' > num[i]-'0'){
                stack.pop(); k--;
            }
            
            if(!stack.empty() || num[i]!='0'){
                stack.push(num[i]);
            }
            
        }
        
        while(!stack.empty() && k--){
            stack.pop();
        }
        if(stack.empty()){
            return "0";
        }
        
        string ans="";
        while(!stack.empty()){
            ans = stack.top() + ans;
            stack.pop();
        }
        return ans;
    }
};

