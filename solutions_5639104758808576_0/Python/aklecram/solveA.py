INPUT='A-small-attempt0.in'
OUTPUT='A-small-attempt0.out'

def calculate(counts):
    result = 0
    current = 0
    for c in range(len(counts)):
        missing = max(0, c-current)
        result += missing
        current += missing + counts[c]
    return result

with open(INPUT, 'r') as f, open(OUTPUT, 'w') as out:
    cases = int(f.readline())
    for c in range(cases):
        line = f.readline().split(" ")
        count = int(line[0])
        counts = [int(i) for i in line[1][:count+1]]
        out.write("Case #%s: %s\n" % (c+1,calculate(counts)))
