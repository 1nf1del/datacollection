import sys
import string

def main():
  f = sys.stdin
  datasets = f.readline()
  for j in range(string.atoi(datasets)):
    count = 0
    line = f.readline()
    line = line.split()
    a = string.atoi(line[0])
    b = string.atoi(line[1])
    pairs = []
    for num in range(a,b):
      strnum = str(num)
      digits = len(strnum)
      for i in range(1,digits):
        recycle = strnum[i:]+strnum[:i]
        r = string.atoi(recycle)
        if r > num and len(str(r)) == digits and r <= b:
          if not pairs.count((num,r)):
            count+=1
            pairs.append((num,r))
    print("Case #" + str(j+1) + ": " + str(count))
          



if __name__ == '__main__':
  main()

