a1 = eval(input("Enter elements of first list"))
print(a1)
a2 = eval(input("Enter elements of second list"))
print(a2)
n1 = len(a1)
n2 = len(a2)
flag = 0
if n1 != n2:
	flag = 1
else:
	d = {}
	for item in a1:
		if item not in d:
			d[item]=True
	for item in a2:
		if item not in d:
			flag = 1
			break
	if flag == 1:
		print("Not same")
	else:
		print("Same")

