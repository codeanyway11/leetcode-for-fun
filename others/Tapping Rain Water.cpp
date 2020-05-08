class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0; int right = n;
        vector<int> rightMax(n, 0);
        vector<int> leftMax(n, 0);
        
        if(n <1){
            return 0;
        }
        
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];
        
        for(int i=1; i<n; i++){
            leftMax[i] = max(height[i], leftMax[i-1]);
        }
        
        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(height[i], rightMax[i+1]);
        }
        
        int ans = 0;
        for(int i=1; i<n-1; i++){
            ans+= min(rightMax[i], leftMax[i]) - height[i];
        }
        
        return ans;
    }
};



// Stack Based Approach

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int current = 0; int right = n;
        if(n <1){
            return 0;
        }
        
        stack<int> stack;
        
        int ans = 0;
        while(current < right){
            while(!stack.empty() && height[current]> height[stack.top()]){
                int top = stack.top();
                int topValue = height[top];
                stack.pop();
                if(stack.empty()){
                    break;
                }
                
                ans+= (min(height[current], height[stack.top()])- topValue) *(current-stack.top()-1);
                
            }
            stack.push(current++);
        }
        
        
        return ans;
    }
};

