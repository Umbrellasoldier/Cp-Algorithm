def isprime(n:int)->bool:
    i=2
    while i<=n//i:
        if n%i==0:
            return False
        i+=1
    return n>=2