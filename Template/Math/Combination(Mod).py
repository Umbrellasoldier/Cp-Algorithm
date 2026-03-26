MOD=1_000_000_007
MX=100_001

fac=[0]*MX
fac[0]=1
for i in range(1,MX):
    fac[i]=fac[i-1]*i%MOD

inv_f=[0]*MX
inv_f[-1]=pow(fac[-1],-1,MOD)
inv=[0]*MX
for i in range(MX-1,0,-1):
    inv_f[i-1]=inv_f[i]*i%MOD
    inv[i]=fac[i-1]*inv_f[i]%MOD

def comb(n:int,m:int)->int:
    return fac[n]*inv_f[m]*inv_f[n-m]%MOD if 0<=m<=n else 0

def fact(n:int)->int:
    return fac[n]

def infact(n:int)->int:
    return inv_f[n]

def inv(n:int)->int:
    return inv[n]