lista1 = [1,2,3,4,5,6,7, 18]
lista2 = [11,12,13,14,15,16,17]

for i in range(50):
    if lista1[i] > lista2[i]:
        j = i
        while lista1[i] > lista2[i]:
            listaTotal.append(lista2[j])
            j = j +1
    else:
        j = i
        while lista2[i] > lista1[j]:
            listaTotal.append(lista1[j])
            j = j + 1