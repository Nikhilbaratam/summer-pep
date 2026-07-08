class Solution {
public:

    vector<int> findnse(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }

        return ans;
    }

    vector<int> findpse(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }

        return ans;
    }

    int mod = 1e9 + 7;

    int sumSubarrayMins(vector<int>& arr) {

        vector<int> nse = findnse(arr);
        vector<int> pse = findpse(arr);

        int n = arr.size();
        long long sum = 0;

        for(int i=0;i<n;i++){

            long long left = i - pse[i];
            long long right = nse[i] - i;

            long long freq = left * right;

            sum = (sum + (freq * arr[i]) % mod) % mod;
        }

        return sum;
    }
};