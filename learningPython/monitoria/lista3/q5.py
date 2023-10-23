n = int(input("Digite um número: "))

palavra = []

for i in range(n):
    letra = input("Digite uma letra: ") 
    palavra.append(letra)

palavraInversa = []

for i in range(len(palavra) -1 , 0, -1):
    palavraInversa.append(palavra[i])

aux = 0

for i in range(len(palavra)):
    if palavra[i] != palavraInversa[i]
        print("Este não é um palíndromo")
        aux = 1
        break

if aux == 0:
    print("Este é um palíndromo!")