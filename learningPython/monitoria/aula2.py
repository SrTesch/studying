import random
seila = []

for i in range(100):
    n = random.randint(1,100)
    seila.append(n)

k = int(input("Digite um valor: "))

resultado = []

for i in range(len(seila)):
    if seila[i] == k:
        resultado.append(i)

if len(resultado) == 0:
    print("Valor nao encontrado")
else:
    print(resultado)
