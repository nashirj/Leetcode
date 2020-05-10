'''
997. Find the Town Judge
In a town, there are N people labelled from 1 to N.  There is a rumor
    that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing
    that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of
    the town judge.  Otherwise, return -1. 

Example 1:
Input: N = 2, trust = [[1,2]]
Output: 2

Example 2:
Input: N = 3, trust = [[1,3],[2,3]]
Output: 3

Example 3:
Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1

Example 4:
Input: N = 3, trust = [[1,2],[2,3]]
Output: -1

Example 5:
Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3

Note:
1 <= N <= 1000
trust.length <= 10000
trust[i] are all different
trust[i][0] != trust[i][1]
1 <= trust[i][0], trust[i][1] <= N

'''
# inspired by lee's awesome solution
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        # model the town as a directed graph
        # if a vertex has degree n-1, then it is the judge
        # if a person is trusted, then increment their degree
        # if a person trusts someone else, then decrement their degree
        # the only way for a vertex to have degree n-1 is if the person
        # trusts no one and is trusted by everyone
        
        people = [0]*(N+1) # nth element may be accessed
        for i, j in trust:
            people[i] -= 1
            people[j] += 1
        
        for i in range(1,N+1):
            if people[i] == N-1:
                return i
        
        return -1

# my first solution
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        # make dictionary with key: cand, val: list of all people that trust cand
        # for each candidate, check that all townspeople (except themselves) trust them        
        townspeople = set([t[0] for t in trust])
        judge_candidates = {}
        for i in range(1, N+1):
            if i not in townspeople:
                judge_candidates[i] = set()
                
        for t in trust:
            if t[1] in judge_candidates:
                judge_candidates[t[1]].add(t[0])
        
        for c, t in judge_candidates.items():
            t.add(c)
            trusted = True
            for i in range(1, N+1):
                if i not in t:
                    trusted = False
                    break
            if trusted:
                return c
        
        return -1
        