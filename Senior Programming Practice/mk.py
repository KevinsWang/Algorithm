import os

root = os.getcwd()

n = 36

for i in range(n, n + 1):
    dirpath = root + '\\{}'.format(i)
    filepath = dirpath + '\\{}.cpp'.format(i)
    isExists = os.path.exists(dirpath)
    if not isExists:
        os.mkdir(dirpath)
        file = open(filepath, 'w')
        file.close()
