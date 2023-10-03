import random

lista = []

for i in range(100):
    lista.append(random.randint(1,100))

print(lista)


# Loop externo para iterar sobre os índices da lista
for i in range(len(lista)):
    # Inicializa o índice do menor elemento como o índice atual
    menor = i

    # Loop interno para encontrar o índice do menor elemento
    for j in range(i + 1, len(lista)):
        if lista[j] < lista[menor]:
            menor = j

    # Se o elemento atual não é o menor, troca-os
    if lista[i] != lista[menor]:
        aux = lista[i]
        lista[i] = lista[menor]
        lista[menor] = aux

# Imprime a lista ordenada
print(lista)