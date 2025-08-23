We are given a string. We can insert char at any index of the string.
We need to find the min number of insertions required to make the string a palindrome.

Solution:

if string is already a palindrome - we return 0. No insertions required since string is already a palindrome.

If not, we find the longest palindromic subsequence (lps) of the string. This will be the longest subsequence which is palindrome.
Now in order to make the entire string a palindrome, we need to insert the remaining characters which are not part of the lps.
Hence min insertions required = length of string - length of lps.

s = "mbadm"
lps(s) = "mam"
Insertions required = 5 - 3 = 2
We need to insert 2 char correspondings to "b" and "d" to make it a palindrome.

ans = s.length() - lps(s);
lps(s) = lcs(s, reverse(s));