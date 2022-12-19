def qual_maior(lista):
    maior = lista[0]
    for i in lista:
        if i > maior:
            maior = i

    return maior

print(qual_maior([1,2,3,4]))