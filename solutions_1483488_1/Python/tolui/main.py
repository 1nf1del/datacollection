'''
Created on Apr 14, 2012

@author: disqiu
'''
import file
import recycle

if __name__ == '__main__':
    lines = file.read_file('C-large.in')
    i=0
    write = []
    
    N = int(lines[0][0])
    for line in lines:
        print (i+0.0)/N
        if i != 0:
            line_number = line.split(" ")
            A = int(line_number[0])
            B = int(line_number[1])

            recycled=0            
        
            for f in range(A,B+1):
                recycled+= recycle.is_recyclable(f, B)

            write.append("Case #"+str(i)+": "+str(recycled)+"\n")    
        i+=1
    file.write_file(write,'C-large.out')