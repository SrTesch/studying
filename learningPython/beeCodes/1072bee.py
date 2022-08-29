x = int(input())
contIn = 0
contOut = 0
for i in range(0, x):
    y = int(input())
    if y <= 20 and y >= 10:
        contIn += 1
    else:
        contOut += 1

print("{} in".format(contIn))
print("{} out".format(contOut))