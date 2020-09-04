class Solution {
public:
    bool isDigitLead(string str) {
        int idx = str.find(' ');
        
        return isdigit(str[idx+1]);
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digit;
        vector<string> alpha;
        
        for(auto s : logs) {
           if(isDigitLead(s)) 
               digit.push_back(s);
           else
               alpha.push_back(s) ;   
        }
        
        sort(alpha.begin(), alpha.end(), [](string a, string b)
             {
                 int id1 = a.find(' ');
                 int id2 = b.find(' ');
                 
                 return a.substr(id1 + 1) <= b.substr(id2+1);
             });
        
        alpha.insert(alpha.end(), digit.begin(), digit.end());
        
        return alpha;
    }
};
