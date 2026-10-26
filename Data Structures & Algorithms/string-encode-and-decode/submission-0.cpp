class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for(auto &i:strs)
            encoded += to_string(i.size()) + "#" + i;
        
        return encoded;

    }

    vector<string> decode(string s) {
        int n = s.size();
        vector<string> decoded;

        string tc = "";

        for(int i=0; i<n; i++){
            if(s[i] == '#'){
                int len = stoi(tc);
                decoded.push_back(s.substr(i+1, len));
                i += len;
                tc = "";

            }else tc += s[i];
            
        }

        return decoded;

    }
};
