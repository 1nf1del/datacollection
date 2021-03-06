def multiply(a, b):
    s1, c1 = a
    s2, c2 = b
    s, c = s1 * s2, '1'
    if c1 == '1':
        c = c2
    elif c2 == '1':
        c = c1
    elif c1 == c2:
        s *= -1
        c = '1'
    elif c1 == 'i' and c2 == 'j':
        c = 'k'
    elif c1 == 'i' and c2 == 'k':
        s *= -1
        c = 'j'
    elif c1 == 'j' and c2 == 'k':
        c = 'i'
    elif c1 == 'j' and c2 == 'i':
        s *= -1
        c = 'k'
    elif c1 == 'k' and c2 == 'i':
        c = 'j'
    elif c1 == 'k' and c2 == 'j':
        s *= -1
        c = 'i'
    return s, c


def solve(case,n,numb,alph):

    res = ""
    for t in range(n):

        L, X = map(int, numb.split())
        single = str(alph)

        val = (1, '1')
        for c in single * (X % 4):
            val = multiply(val, (1, c))

        result = val == (-1, '1')

        if result:

            S = single * (X % 4 + (4 if X >= 4 else 0))

            p1 = p2 = -1

            n1 = (1, '1')
            for i in range(len(S)):
                n1 = multiply(n1, (1, S[i]))
                if n1 == (1, 'i'):
                    p1 = i
                    break

            n2 = (1, '1')
            for i in range(len(S)-1, -1, -1):
                n2 = multiply((1, S[i]), n2)
                if n2 == (1, 'k'):
                    p2 = i
                    break

            result = (p1 > -1 and p2 > -1) and p1 < p2 + (X * L - len(S))

        _x = 'YES' if result else 'NO'
        return "Case #%s: %s\r\n" % (case, _x)
    
infile  = open("C-small-attempt0.in", "r")
outfile = open("C-small-attempt0.out","w")
cases = int(infile.readline().strip())
for o in range(1,cases+1):
    n = infile.readline().strip()
    a = infile.readline().strip()
    outfile.write(solve(o,1,n,a))
infile.close()
outfile.close()