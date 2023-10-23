dec= [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
roman = ["M", "CM", 'D', "CD", "C", "XC", 'L', "XL", 'X', "IX" , 'V', "IV", 'I']

romFinal = ""

numero = int(input("Digite um valor: "))

for i in range(0, len(dec)):
    n2 = numero // dec[i]
    for j in range(n2):
        romFinal.append(roman[i])
    numero = numero % dec[i]
