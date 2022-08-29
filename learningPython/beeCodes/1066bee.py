contImpar = 0
contPar = 0 
positivos = 0 
negativos = 0
for i in range(0, 5):
    x = int(input())
    if x > 0:
        positivos += 1
    elif x < 0:
        negativos += 1
    
    if x%2 == 0:
        contPar +=1
    else:
        contImpar += 1

print("{} valor(es) par(es)".format(contPar))
print("{} valor(es) impar(es)".format(contImpar))
print("{} valor(es) positivo(s)".format(positivos))
print("{} valor(es) negativo(s)".format(negativos))