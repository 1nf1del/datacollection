from math import *
from decimal import *

getcontext().prec = 100

tlim = int(raw_input())
for T in xrange(tlim):
    r, t = [int(x) for x in raw_input().split()]
    a = 2
    b = 2 * r - 1
    c = - t
    det = Decimal(b * b - 4 * a * c)
    ans = (-b + det.sqrt()) / 2 / a
    print "Case #%d: %d" % (T + 1, int(ans))