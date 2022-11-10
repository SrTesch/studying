x = int(input("digite um número "))
y = int(input("digite um número "))
z = int(input("digite um número "))

iguais = 0

if x == y and x == z: 
    iguais = 3
elif x == y or x == z or y == z:
    iguais = 2

print(iguais)