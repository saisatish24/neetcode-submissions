class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for ( string s : strs){

            vector<int> freq(26, 0);

            // for ( int i = 0; i < 26; i++){
            //     freq[i] = 0;
            // }

            for ( int i = 0; i < s.size(); i++){
                freq[s[i] - 'a']++;
            }
            string key = "";

            for ( int i = 0; i < 26; i++ ){
                key += to_string(freq[i]) + "#";
            }

            mp[key].push_back(s);   
        }

        vector<vector<string>> result;
        for ( auto &it : mp){
            result.push_back(it.second);
        }

        return result;
        
    }
};
