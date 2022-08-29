maior = 0
pos = 0
for i in range (0,100):
        x = int(input())
        if x > maior:
            maior = x
            pos = i + 1
        
print(maior)
print(pos)