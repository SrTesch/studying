#https://www.beecrowd.com.br/judge/pt/problems/view/1045
x = input().split()
a, b, c = float(x[0]), float(x[1]), float(x[2])
aux = 0

if b >= a  and b >= c : 
    aux = b #guardando valor de B
    b = a
    a = aux
elif c >= a and c >= b : 
    aux = c
    c = a
    a = aux

if a >= b + c :
    print('NAO FORMA TRIANGULO')
else:
    if a**2 == b**2 + c**2 :
        print('TRIANGULO RETANGULO')
    if a**2 > b**2 + c**2 : 
        print('TRIANGULO OBTUSANGULO')
    if a**2 < b**2 + c**2:
        print('TRIANGULO ACUTANGULO')
    if a == b and a == c and c == b: 
        print('TRIANGULO EQUILATERO')
    if a == b and a != c or b == c and b != a or c == a and c != b:
        print('TRIANGULO ISOSCELES')