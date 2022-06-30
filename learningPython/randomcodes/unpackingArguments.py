def calculateArea(width, length):
    area = width * length
    print(area)

squareArea = [20, 40]

calculateArea(squareArea[0], squareArea[1])

calculateArea(*squareArea)