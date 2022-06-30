#this function will sum all values
def calculateNumbers(*arguments):
    total = 0
    for x in arguments:
        total += x
        print(total)

calculateNumbers(23, 23, 100, 100, 300)