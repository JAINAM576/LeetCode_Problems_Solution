class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        ans=[]
        i=0
        j=0
        words1=s1.split(" ")
        words2=s2.split(" ")
        n=len(words1)
        m=len(words2)

        while i <n or j<m:

            if i<n  and words1.count(words1[i])+words2.count(words1[i])==1 and words1[i] not in ans :
                ans.append(words1[i])
            if j<m and words1.count(words2[j])+words2.count(words2[j])==1 and words2[j]  not in ans:
                ans.append(words2[j])
              
            i+=1
            j+=1
        return ans
        