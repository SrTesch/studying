x = int(input("Digite um valor: "))
y = int(input("Digite um valor maior do que o ultimo: "))
somatotal = 0
mult = 1
for i in range(x, y + 1, 1):
    if i % 2 == 0:
        somatotal = somatotal + i
    else:
        mult = mult * i

print(f"A soma dos números pares entre os números digitados é {somatotal} e a multiplicação dos número ímpares é {mult}")