from collections import defaultdict
def kDistinctChars(k, str):
    n = len(str)
    mp = defaultdict(int)       # char -> freq
    i = j = ans = 0
    while j < n:
        mp[str[j]]+=1
        while len(mp) > k:
            mp[str[i]] -= 1
            if mp[str[i]] == 0:
                del mp[str[i]]
            i+=1
        ans = max(ans, j - i + 1)
        j+=1

    return ans

