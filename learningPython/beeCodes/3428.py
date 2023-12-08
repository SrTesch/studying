n = int(input("Digite o número total de balões: "))

alturas = list(map(int, input().split()))

def pegaPosMaiorAltura(vetor):
    posMaior = 0

    for i in range(len(vetor)):
        if vetor[i] > vetor[posMaior]:
            posMaior = i
    
    return posMaior


contadorDeFlechas = 0

while n != 0:

    contadorDeFlechas += 1
    
    posMaiorAltura = pegaPosMaiorAltura(alturas)
    alturaAtual = alturas[posMaiorAltura] - 1
    alturas[posMaiorAltura] = - 1

    n -= 1

    for i in range(posMaiorAltura + 1, len(alturas), 1):
        if alturas[i] == alturaAtual:
            alturas[i] = -1
            n -= 1
            alturaAtual -= 1

print(f"O número total de flechas foi {contadorDeFlechas}")