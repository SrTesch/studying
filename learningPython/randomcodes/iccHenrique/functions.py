def media(x):
    total = 0
    for i in x:
        total = total + i
    y = total/len(x)
    return y

lista = []

while(True):
    print("Digite -1 para sair")
    x = int(input("Digite um numero para adicionar à lista: "))
    if x == -1:
        break
    lista.append(x)

media_total = media(lista)
print(lista)
print(media_total)