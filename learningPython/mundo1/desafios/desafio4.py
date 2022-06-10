from cmath import isnan
from curses.ascii import isalnum, isalpha, islower, isspace, isupper
from pydoc import isdata


n = input('Digite algo: ')
print('O tipo primitivo disso é:', type(n))
print('Só tem espaços?', n.isspace())
print('É um número?', n.isnumeric())
print('É alfabético?', n.isalpha())
print('É alfanumérico?', n.isalnum())
print('Está em maiúsculas?', n.isupper())
print('Está em minúsculas?', n.islower())