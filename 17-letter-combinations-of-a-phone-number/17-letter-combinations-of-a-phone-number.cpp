class Solution {
public:
    void findTheLetterCombinations(string str,string digits, unordered_map<char,string>& letters, vector<string>& combinations){
        if(digits.length()==0){
            combinations.push_back(str);
            return;
        }
        string alpha = letters[digits[0]];
        for(int i=0;i<alpha.length();i++){
            findTheLetterCombinations(str+alpha[i],digits.substr(1,digits.length()),letters,combinations);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        unordered_map<char,string> letters = 
        {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        
        vector<string> combinations;
        findTheLetterCombinations("",digits,letters,combinations);
        return combinations;
        
    }
};