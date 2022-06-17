alt = float(input('Digite a altura da parede: '))
larg = float(input('Digite a largura da parede: '))

area = alt * larg
tintaNecessaria = area/2
print('A sua parede tem {}m² e necessita de {} litros de tinta.'.format(area, tintaNecessaria))