def sayHi():
    print('Hi, professor')

sayHi()

def getURL(website = 'google.com'):
    if website == "https://www.instagram.com/peeh_tesch":
        print(website + 'is your personal website, right?')
    elif website == 'https://github.com/SrTesch':
        print(website + ' is your professional website, right?')
getURL('https://github.com/SrTesch')
getURL('https://www.instagram.com/peeh_tesch')