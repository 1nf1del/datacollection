def palend(x):
    v1 = []
    v2 = []
    while(x)>0:
        v1.append(x%10)
        v2.insert(0,x%10)
        x = x/10
    return v1 == v2



T = input()

"""
vec = [1,4,9]

for i in range(10, 10**7):
    if i%10==0  :
        continue
    if palend(i*i) and palend(i):
        vec.append(i*i)


print vec
"""

vec = [1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004]






for t in range(T):
    s = raw_input()
    s = s.split()
    a = int(s[0])
    b = int(s[1])
    

    s = 0
    for i in vec:
        if a <= i <=b:
            s+=1

    print "Case #%d: %d" %(t+1, s)


