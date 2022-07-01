x = input().split()
a, b, c, d= int(x[0]), int(x[1]), int(x[2]), int(x[3])

if a == c and b == d:
    horas = 24
    minutos = 0
elif a > c:
    horas = 24
    horas -= a - c
else:
    horas = c - a

if b > d:
    horas -= 1
    minutos = 60
    minutos -= b - d
else:
    minutos = d - b

if a == c and b > d:
    horas = 23
    minutos = 60
    minutos -= b - d

print('O JOGO DUROU {} HORA(S) E {} MINUTO(S)'.format(horas, minutos))