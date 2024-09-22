# **Search Query Autocomplete**
Functionality of designing a search query based autocomplete system - for search engines. <br>

### Assumptions:
• The users will input a sentence (which may have multiple words and ends with special character '#'). <br>
• For each character if the user type except '#', we would need to return the top 3 previously entered and most frequently queried sentences that have prefix the same as the part of sentence already typed. <br>
• The frequency for a sentence is defined as the number of times a user typed the exactly same sentence before. <br>
• The returned top 3 sentences should be sorted by frequency (The first is the most frequent).  If several sentences have the same frequency, we will use ASCII-code lexicographical order (smaller one appears first). <br>
• If less than 3 valid sentences exist, then we will just return as many as we can. <br>
• When the input is a special character, it means the sentence ends, and in this case, we will return an empty list. <br>

### Functionality:

➡ **AutoCompleteSystem** **Methods**: Constructor of main class, the input is previously used data. Sentences will be a string array consists of previously typed sentences. Times will be the corresponding times a sentence has been typed. Our system should record these historical sentences. <br>

➡ **Input**: The input c is the next character typed by the user. The character will only be lower-case letters ('a' to 'z'), blank space (' ') or a special character ('#'). Also, the previously typed sentence should be recorded in our system. The output an array will be the top 3 historical sentences that have prefix the same as the part of sentence already typed. <br>

### Example:

Operation:
AutoCompleteSystem(["i love icecream", "island",
"ironman", "i love football"], [5,3,2,2])

The system have already tracked down the 
following sentences and their corresponding 
times: 
"i love icecream" : 5 times 
"island" : 3 times 
"ironman" : 2 times 
"i love football" : 2 times 

Now, the user begins another search: 

Operation: input('i') 
Output: 
["i love icecream", "island","i love 
                       football"] 

Explanation: 
There are four sentences that have prefix 
"i". Among them, "ironman" and "i love 
football" have same frequency. Since 
' ' has ASCII code 32 and 'r' has ASCII code
 114, "i love football" should be in 
front of "ironman". Also we only need to 
output top 3 most frequent sentences, so 
"ironman" will be ignored. 

Operation: input(' ') 
Output: ["i love icecream","i love football"] 
Explanation: 
There are only two sentences that have prefix 
"i ". 

Operation: input('a') 
Output: [] 
Explanation: 
There are no sentences that have prefix "i a"

Operation: input('#') 
Output: [] 
Explanation: 
The user finished the input, the sentence 
"i a" should be saved as a historical 
sentence in system. And the next input 
will be counted as a new search.

### Expected Time Complexity:
➡ O(n*max|L|), per input query where n represents the number of historical sentences in the system and L is the maximum length of the words.

#### Tags:
➡ Strings, Tries, DSA, System Design
