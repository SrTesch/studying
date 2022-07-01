x = input().split()
a, b = int(x[0]), int(x[1])
aux = 0
if a > b:
    aux += 24
    dif = a-b
    aux -= dif
    print('O JOGO DUROU {} HORA(S)'.format(aux))
elif a < b:
    dif = b - a
    print('O JOGO DUROU {} HORA(S)'.format(dif))
elif a == b:
    print('O JOGO DUROU 24 HORA(S)')