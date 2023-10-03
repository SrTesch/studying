import random

vetor1 = []
for i in range(50):
    vetor1.append(random.randint(1,50))


for i in range(len(vetor1)):
    # Inicializa o índice do menor elemento como o índice atual
    menor = i

    # Loop interno para encontrar o índice do menor elemento
    for j in range(i + 1, len(vetor1)):
        if vetor1[j] < vetor1[menor]:
            menor = j

    # Se o elemento atual não é o menor, troca-os
    if vetor1[i] != vetor1[menor]:
        aux = vetor1[i]
        vetor1[i] = vetor1[menor]
        vetor1[menor] = aux


vetor2 = []
for i in range(50):
    vetor2.append(random.randint(1,50))
for i in range(len(vetor2)):
    # Inicializa o índice do menor elemento como o índice atual
    menor = i

    # Loop interno para encontrar o índice do menor elemento
    for j in range(i + 1, len(vetor2)):
        if vetor2[j] < vetor2[menor]:
            menor = j

    # Se o elemento atual não é o menor, troca-os
    if vetor2[i] != vetor2[menor]:
        aux = vetor2[i]
        vetor2[i] = vetor2[menor]
        vetor2[menor] = aux

print(vetor1)
print(vetor2)

vetorFinal = []


i = 0
j = 0


while True:
    
    if i == 50 and j == 50:
        break # isto serve para parar o while

    if i == 50:
        vetorFinal.append(vetor2[j])
        j = j + 1
        continue #isso serve para ir para a proxima iteração do while

    if j == 50:
        vetorFinal.append(vetor1[i])
        i = i + 1
        continue

    if vetor1[i] <= vetor2[j]:
        vetorFinal.append(vetor1[i])
        i = i + 1
    else:
        vetorFinal.append(vetor2[j])
        j = j + 1

print("vetor final : \n")
print(vetorFinal)
print(f"tamanho no final: {len(vetorFinal)}")