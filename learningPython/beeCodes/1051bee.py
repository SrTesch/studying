salary = float(input())

if salary <= 2000.00:
    print('Isento')
elif salary >2000.00 and salary <= 3000.00:
    salary -= 2000
    salary *= 0.08
    #print('')
    print('R$ {:.2f}'.format(salary))
elif salary > 3000.00 and salary <= 4500.00:
    salary -= 2000
    aux1 = 1000 * 0.08
    salary -= 1000
    aux1 += (salary*0.18)
    print('R$ {:.2f}'.format(aux1))
elif salary > 4500.00:
    salary -= 2000
    aux1 = 1000 * 0.08
    salary -= 1000
    aux1 += (1500.00*0.18)
    salary -= 1500
    aux1 += (salary*0.28)
    print('R$ {:.2f}'.format(aux1))