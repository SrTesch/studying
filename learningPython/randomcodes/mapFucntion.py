t = lambda var: var*2

seq = [1,2,3,4,5]

x = list(map(lambda num: num*3, seq))
print(x)

y = list(filter(lambda num: num%2 == 0, x))

print(y)