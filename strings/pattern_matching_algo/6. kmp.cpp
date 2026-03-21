#include <bits/stdc++.h>
using namespace std;

The Naive pattern searching algorithm doesn’t work well in cases where we see many matching characters followed by a mismatching character.
The basic idea behind KMP’s algorithm is: whenever we detect a mismatch (after some matches), we already know some of the 
characters in the text of the next window. We take advantage of this information to avoid matching the characters that we know will anyway match.
 We compare first window of txt with pat
txt = "AAAAABAAABA" 
pat = "AAAA"  [Initial position]
We find a match. This is same as Naive String Matching.

In the next step, we compare next window of txt with pat.
txt = "AAAAABAAABA" 
pat =  "AAAA" [Pattern shifted one position]
This is where KMP does optimization over Naive. In this second window, we only compare fourth A of pattern with fourth character of 
current window of text to decide whether current window matches or not. Since we know first three characters will anyway match, we skipped 
matching first three characters. 

Need of Preprocessing?
An important question arises how to know how many characters to be skipped. To know this, we pre-process pattern and prepare an integer array 
lps[] that tells us the count of characters to be skipped. 

Preprocessing Overview:

KMP algorithm preprocesses pat[] and constructs an auxiliary lps[] of size m (same as size of pattern) which is used to skip characters
while matching.
name lps indicates longest proper prefix which is also suffix.. A proper prefix is prefix with whole string not allowed. 
For example, prefixes of “ABC” are “”, “A”, “AB” and “ABC”. Proper prefixes are “”, “A” and “AB”. 

For each sub-pattern pat[0..i] where i = 0 to m-1, lps[i] stores length of the maximum matching proper prefix which is also a suffix of the
sub-pattern pat[0..i].
  lps[i] = the longest proper prefix of pat[0..i] 
              which is also a suffix of pat[0..i]. 
              
              

Searching Algorithm:

We start comparison of pat[j] with j = 0 with characters of current window of text.
We keep matching characters txt[i] and pat[j] and keep incrementing i and j while pat[j] and txt[i] keep matching.
When we see a mismatch
We know that characters pat[0..j-1] match with txt[i-j…i-1] (Note that j starts with 0 and increment it only when there is a match).
We also know (from above definition) that lps[j-1] is count of characters of pat[0…j-1] that are both proper prefix and suffix.
From above two points, we can conclude that we do not need to match these lps[j-1] characters with txt[i-j…i-1] because we know that 
these characters will anyway match.   


Preprocessing Algorithm:
In the preprocessing part, we calculate values in lps[]. To do that, we keep track of the length of the longest prefix suffix value
(we use len variable for this purpose) for the previous index. We initialize lps[0] and len as 0. If pat[len] and pat[i] match, we increment
len by 1 and assign the incremented value to lps[i]. If pat[i] and pat[len] do not match and len is not 0, we update len to lps[len-1].


void computeLPSArray(string pat, int M, int* lps)
{
	
	int len = 0;
	lps[0] = 0; // lps[0] is always 0

	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0) {
				len = lps[len - 1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(string pat, string txt)
{
	int M = pat.length();
	int N = txt.length();

	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	int lps[M];

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, M, lps);

	int i = 0, j = 0; 
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			cout<<"pattern found at index "<<i-j<<endl;
			j = lps[j - 1];
		}
		else if (i < N && pat[j] != txt[i]) {
			if (j > 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

int main()
{
	string txt = "ABABDABACDABABCABAB";
	string pat = "ABABCABAB";
	KMPSearch(pat, txt);
	return 0;
}

