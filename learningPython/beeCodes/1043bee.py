x = input().split()
a, b, c =x
a = float(a)
b = float(b)
c = float(c)

if(a + b) > c and (a + c) > b and (b + c) > a:
    perimetro = a + b + c
    print('Perimetro = {}'.format(perimetro))
else:
    area = ((a + b) * c)/2
    print('Area = {}'.format(area))