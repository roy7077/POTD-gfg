class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       int freq[27]={0};
       
       for(auto it:S)
       freq[it-'a']++;
       
       for(auto it:S)
       {
           if(freq[it-'a']==1)
           return it;
       }
       
       return '$';
    }

};
