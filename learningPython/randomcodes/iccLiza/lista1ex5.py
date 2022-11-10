x = int(input("digite um número "))
y = int(input("digite um número "))
z = int(input("digite um número "))

if  x > y and z > y:
    print(f"{y} é o número menor")
elif x < y and x < z:
    print(f"{x} é o número menor")
else:
    print(f"{z} é o número menor")