def pthFactor(n, p):
    # Write your code here
    lfct = set()

    from functools import reduce

    def factors(n):    
        return set(reduce(list.__add__, 
                    ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))

    lfct = factors(n)
    # for i in range(1, n + 1):
    #     if(n%i == 0):
    #         lfct.append(i)
    lfct = list(lfct)
    lfct.sort()

    # for ix in lfct:
    #     print(ix)

    #print(len(lfct))

    if (len(lfct)>=p ):
        return lfct[p - 1]
    else:
        return 0


print(pthFactor(10, 3))