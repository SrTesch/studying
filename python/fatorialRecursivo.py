def batataFervendo(x):
    if(x <= 2):
        return 1
    else:
        return batataFervendo(x-1) + batataFervendo(x-2)