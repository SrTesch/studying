def Escadinha(lista):
    escada = 1
    diferença = lista[1] - lista[0]
    for i in range(1,len(lista)):
        if (lista[i] - lista[i-1] != diferença):
            escada+=1
            diferença = lista[i] - lista[i-1]
    return escada

teste = [2,3,4,4,7,6,8]

print(Escadinha(teste))