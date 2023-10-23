def positions(lista, numero):
    posições = []
    for i in range(len(lista)):
        if lista[i] == numero:
            posições.append(i)

    return posições