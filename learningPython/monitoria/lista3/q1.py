notaInicial = float(input("Digite uma nota: "))
menor = notaInicial
maior = notaInicial

while(True):
    print("Digite -1 para sair!")
    nota = float(input("Digite uma nota: "))

    if nota == -1:
        break

    if nota > maior:
        maior = nota
    elif nota < menor:
        menor = nota

print(f'A maior nota é {maior} e a menor nota é {menor}')
