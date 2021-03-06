def isPrime (x):
	i = 2
	while (i*i <= x):
		if (x % i == 0): return i
		i += 1
		
	return 1

fout = open ("tes.out", "w")
	
k = int(input())
	
cnt = 0
for i in range(1<<14):
	s = str(1) + "{:014b}".format(i) + str(1)	
	ans = []
	for j in range(2, 11):
		ans.append (isPrime(int(s, j)))
		if (ans[-1] == 1): break
		
	print (s, ans)
	if (ans[-1] == 1): continue
	
	cnt += 1
	fout.write (s)
		
	
	for item in ans: fout.write (" {:d}".format(item)) 
	fout.write("\n")
	if (cnt == k): break
		
fout.close()
		
	