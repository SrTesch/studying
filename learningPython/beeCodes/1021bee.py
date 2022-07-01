x = float(input())

nota100 = 0
nota50 = 0
nota20 = 0
nota10 = 0
nota5 = 0
nota2 = 0
moeda100 = 0
moeda50 = 0
moeda25 = 0
moeda10 = 0
moeda5 = 0
moeda1 = 0

x *= 100

while x >= 10000:
    x -= 10000
    nota100 += 1

while x >= 5000:
    x -= 5000
    nota50 += 1
    
while x >= 2000:
    x -= 2000
    nota20 += 1

while x >= 1000:
    x -= 1000
    nota10 += 1

while x >= 500:
    x -= 500
    nota5 += 1

while x >= 200:
    x -= 200
    nota2 += 1

while x >= 100:
    x -= 100
    moeda100 += 1

while x >= 50:
    x -= 50
    moeda50 += 1

while x >= 25:
    x -= 25
    moeda25 += 1

while x >= 10:
    x -= 10
    moeda10 += 1

while x >= 5:
    x -= 5
    moeda5 += 1

while x >= 1:
    x -= 1
    moeda1 += 1

print('NOTAS:')
print('{} nota(s) de R$ 100.00'.format(nota100))
print('{} nota(s) de R$ 50.00'.format(nota50))
print('{} nota(s) de R$ 20.00'.format(nota20))
print('{} nota(s) de R$ 10.00'.format(nota10))
print('{} nota(s) de R$ 5.00'.format(nota5))
print('{} nota(s) de R$ 2.00'.format(nota2))
print('MOEDAS:')
print('{} moeda(s) de R$ 1.00'.format(moeda100))
print('{} moeda(s) de R$ 0.50'.format(moeda50))
print('{} moeda(s) de R$ 0.25'.format(moeda25))
print('{} moeda(s) de R$ 0.10'.format(moeda10))
print('{} moeda(s) de R$ 0.05'.format(moeda5))
print('{} moeda(s) de R$ 0.01'.format(moeda1))
