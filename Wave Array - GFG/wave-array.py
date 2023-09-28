from typing import List

class Solution:
    def convertToWave(self, array_length: int, array: List[int]) -> None:
        # Loop through the array with a step of 2 (starting from index 1)
        for i in range(1, array_length, 2):
            # Swap the current element with the next element
            array[i - 1], array[i] = array[i], array[i - 1]

#{ 
 # Driver Code Starts
class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        
        a=IntArray().Input(n)
        
        obj = Solution()
        obj.convertToWave(n, a)
        IntArray().Print(a)

# } Driver Code Ends