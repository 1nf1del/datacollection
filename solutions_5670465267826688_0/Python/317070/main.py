""" imports """
import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos

""" global variables """

""" classes """
""" functions """

indexing = {"1":0,
            "i":1,
            "j":2,
            "k":3}

value_matrix = [["1","i","j","k"],
                ["i","1","k","j"],
                ["j","k","1","i"],
                ["k","j","i","1"],]

sign = [[True, True, True, True],
        [True,False, True,False],
        [True,False,False, True],
        [True, True,False,False],]

def resolve(s,pos=True):
    while len(s)>1:
        a = s[-2]
        b = s[-1]
        s = s[:-2]+value_matrix[indexing[a]][indexing[b]]
        pos = not (pos ^ sign[indexing[a]][indexing[b]])
    return s,pos


def solve(n,repeat,s):
    
    modulo = -1
    for i in xrange(1,5):
        if resolve(s*i)==("1",True):
            modulo = i
            break
        
    assert modulo!=-1, "Woopsie"
    
    for useful_repeats in xrange( repeat%modulo, 15, modulo):
        
        if useful_repeats > repeat:
            break
        
        string = s * useful_repeats
        
        if resolve(string)!=('1',False):
            continue
        
        for i in xrange(1,len(string)):
            if resolve(string[:i])==("i",True):
                for j in xrange(i+1, len(string)):
                    if resolve(string[i:j])==("j",True) and resolve(string[j:])==("k",True):
                        return "YES"
    
    return "NO"
    
    
""" parse input """
output = ""
TIC = time.time()
with open(sys.argv[1] if len(sys.argv) > 1 else "default.in") as f:
    def read_ints():
        return [int(x) for x in f.readline().strip().split(' ')]
    def read_strs():
        return [x for x in f.readline().strip().split(' ')]    
    def read_floats():
        return [float(x) for x in f.readline().strip().split(' ')]
    
    (numquestions,) = read_ints()
    for questionindex in xrange(numquestions):
        ### parse input ###
        (n,m) = read_ints()
        (s,) = read_strs()
        ### calculate answer ###
        answer = solve(n,m,s)
        ### output ###
        #print "Calculating case #{}...".format(questionindex+1)
        answer_str = "Case #{}: {}".format(questionindex+1, answer)
        output += answer_str + '\n'
        print answer_str
ofile = open('output', 'w').write(output)
TOC = time.time()
#print "done in {} s".format(TOC-TIC)