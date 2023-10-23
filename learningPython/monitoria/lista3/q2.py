def somatorio(x):
    valorFinal = 0
    for i in range(99):
        aux = 2 * i +1
        valorFinal = valorFinal + ( (1 / aux ) * ( (x - 1) / (x + 1) ) ** aux )
    return valorFinal * 2
    