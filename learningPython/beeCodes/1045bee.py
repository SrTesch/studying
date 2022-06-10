#https://www.beecrowd.com.br/judge/pt/problems/view/1045
x = input().split()
a, b, c = x
a = float(a)
b = float(b)
c = float(c)
if a >= b >= c: 
    a = a
    b = b
    c = c
elif b >= a >= c : 
    a = b
    b = a
    c = c
elif c >= a >= b : 
    a = c
    b = a
    c = b

if a >= b +c :
    print('NAO FORMA TRIANGULO')
else:
    if a**2 == b**2 + c**2 :
        print('TRIANGULO RETANGULO')
    if a**2 > b**2 + c**2 : 
        print('TRIANGULO OBTUSANGULO')
    if a**2 < b**2 + c**2:
        print('TRIANGULO ACUTANGULO')
    if a == b == c : 
        print('TRIANGULO EQUILATERO')
    if a == b or b == c or c == a :
        print('TRIANGULO ISOSCELES')