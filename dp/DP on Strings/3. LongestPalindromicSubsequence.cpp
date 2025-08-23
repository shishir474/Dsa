// Longest palindromic subs is same as finding the longest common subsequence between the string and its reverse.
// lps(s) = lcs(s, reverse(s));

ex: s = "bbbab"
    reverse(s) = "babbb"
    lcs(s, reverse(s)) = "bbbb"
    lps(s) = "bbbb"