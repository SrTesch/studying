import math
x = float(input())

if x>=0 and x <=400:
    aux = x*0.15
    new = x + aux
    perc = 15
elif x>400 and x<=800:
    aux = x*0.12
    new = x + aux
    perc = 12
elif x>800 and x<=1200:
    aux = x*0.1
    new = x + aux
    perc = 10
elif x>1200 and x<=2000:
    aux = x*0.07
    new = x + aux
    perc = 7
elif x > 2000:
    aux = x*0.04
    new = x + aux
    perc = 4

print('Novo salario: {:.2f}'.format(new))
print('Reajuste ganho: {:.2f}'.format(aux))
print('Em percentual: {} %'.format(perc))