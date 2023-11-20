n = int(input("Digite o número total de balões: "))

alturas = list(map(int,input().split()))


def pegarPosMaiorAltura(vetor):
    #Neste for eu estava basicamente pegando a maior altura
    maior_altura = 0
    pos = 0
    for i in range(len(vetor)):
        if vetor[i] > maior_altura :
            maior_altura = vetor[i]
            pos = i
    return pos

minFlechas = 0

while(n != 0):
    posMaior = pegarPosMaiorAltura(alturas)
    altura_flecha = alturas[posMaior] -1
    n -= 1
    if n != 0:
        for i in range(posMaior, len(alturas), 1):
            if alturas[i] == altura_flecha:
                n -=1
                altura_flecha -= 1
        minFlechas += 1

print(minFlechas)