class XorBasis:
    def __init__(self,bits):
        self.bits=bits
        self.basis=[0]*bits

    def insert(self,x):
        while x:
            i=x.bit_length()-1
            if self.basis[i]==0:
                self.basis[i]=x
                return
            x^=self.basis[i]
        return

    def max_xor(self)->int:
        res=0
        for i in range(self.bits-1,-1,-1):
            if res^self.basis[i]>res:
                res^=self.basis[i]
        return res