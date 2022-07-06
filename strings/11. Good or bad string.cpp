String S is composed of lowercase alphabets and wildcard characters i.e. '?'. Here, '?' can be replaced by any of the lowercase alphabets. Now you have to classify the given String on the basis of following rules:

If there are more than 3 consonants together or more than 5 vowels together, the String is considered to be "BAD". A String is considered "GOOD" only if it is not “BAD”.

NOTE: String is considered as "BAD" if the above condition is satisfied even once. Else it is "GOOD" and the task is to make the string "BAD".

JAVA Solution:

Approach:

Whenever we encounter a vowel, increment vCount and set cCount as 0.
Whenever we encounter a consonant, increment cCount and set vCount as 0 .
The task is to make the string BAD. So, we increment both vCount and cCount when we encounter ‘?’
Time Complexity: O(|S|)

Space Complexity: O(1)
class Solution {
  public:
    int isGoodorBad(string s) {
        // code here
       int vCount=0,cCount=0;
       for(int i=0;i<s.length();i++){
           if(s[i]=='?'){
               vCount++; cCount++;
           }
           else if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ){
               cCount=0;
               vCount++;
           }
           else{
               vCount=0;
               cCount++;
           }
           if(cCount>3 || vCount>5){
               return 0;
           }
       }
       return 1;      
    }
};