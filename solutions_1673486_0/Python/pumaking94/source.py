f = open("A-small-attempt0.in")

T = int(f.readline())

out = open("A-small.out", 'w')

for i in range(T):
    print("Test Case #%d: " % i)
    line = f.readline().split()

    A = int(line[0])
    B = int(line[1])

    chances = [float(x) for x in f.readline().split()]

    choices = []
    running = 1

    for (j,c) in enumerate(chances):
        choices.append((B+A-2*j+1)*running + (2*B+A-2*j+2)*(1-running))

        running *= c

    choices.append((B-A+1)*running + (2*B-A+2)*(1-running))
    choices.append(B+2)
    print(choices)

    out.write("Case #%d: %f\n" % (i+1, min(choices)))





f.close()
out.close()