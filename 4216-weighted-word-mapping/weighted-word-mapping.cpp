class Solution {
public:
    int findWeight(string word, vector<int>& weights)
    {
        int sum = 0;
        for(auto &it : word)
        {
            sum += weights[it - 'a'];
        }
        return sum % 26;
    }

    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(auto &it : words)
        {
            char letter = 'z' - findWeight(it, weights);
            ans += letter;
        }    
        return ans;
    }
};