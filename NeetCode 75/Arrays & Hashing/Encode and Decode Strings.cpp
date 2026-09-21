class Solution {
public:
    
    string encode(vector<string>& strs) {
        string str1 ="";
        int n = strs.size();
        for(int i=0; i<n; i++){
            string temp = strs[i];
            int len = temp.length();
            str1 += to_string(len)  + '_' + temp;
        }
        return str1;
    }

    vector<string> decode(string s) {
        int n = s.length();
        vector<string> ans;
        
        for(int i =0;i<n;){
            int len =0;

            while(isdigit(s[i])){
                len = len*10 + (s[i] -'0');
                i++;
            }
            i++;//skip '_'
            
            string decode_string  = "";//read string of length len
            while(len--){
                decode_string.push_back(s[i]);
                i++;
            }

            ans.push_back(decode_string);
            
        }
        return ans;
    }

};
