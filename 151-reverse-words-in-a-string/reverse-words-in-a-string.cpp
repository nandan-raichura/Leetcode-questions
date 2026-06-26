class Solution {
public:
    string reverseWords(string s) {
        string word;
        vector<string> words;

        for(char ch:s){
            if(ch==' '){
                if(!word.empty()){
                    words.push_back(word);// if there is space will add our word into the vector
                    word.clear();// we will clean it for upcomming words
                }
            }else{
                word+=ch;
            }
        }
        // after the loop last element will be not stored in the ans becz after finishing the last element there is no space so we will do it manually

        if(!word.empty()){
            words.push_back(word);
        }

        // we will reverse liest/ vector
        string ans;
       
        for(int i=(int)words.size()-1;i>=0;i--){
            ans+=words[i];
            if(i!=0){
                ans+=' ';
            }
            
        }
        return ans;

    }
};