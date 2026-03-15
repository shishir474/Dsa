class Solution:
    # utility function which calculate x^n using binary exponentiation
    def myPowHelper(self, x, n):
        if n == 0:
            return 1

        tres = self.myPowHelper(x,n//2)

        if n%2 == 0:
            return tres * tres
        else:
            return tres * tres * x


    def myPow(self, x: float, n: int) -> float:
        if n > 0:
            return self.myPowHelper(x,n)
        else:
            return 1/self.myPowHelper(x,abs(n))