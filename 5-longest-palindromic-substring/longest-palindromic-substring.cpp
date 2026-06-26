class Solution {
public:

     bool isPalindrome(string &s,int left,int right){// we recive the start and end of the array
     while(left<right){
        if(s[left]!=s[right]){
            return false;
        }
        left++;
        right--;
     }
        return true;
     }

    string longestPalindrome(string s) {
     
        int n=s.length();
        
        for(int length=n;length>=1;length--){// we will go largest length to the smallest, like we will just decrease the size of the string by one every time , n->0 it willsave many itreation, we will start from the hihest index


            for(int start=0;length+start<=n;start++){

               if(isPalindrome(s, start, start + length - 1)){// faster helper function to solve this
                    return s.substr(start, length); // Only copy the winner string ONCE
                }
                }
            }
        

        return "";
    }
};