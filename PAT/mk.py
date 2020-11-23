import os

root = os.getcwd()


for i in range(1033, 1155):
    dirpath = root + '\\{}'.format(i)
    filepath = dirpath + '\\{}.cpp'.format(i)
    isExists = os.path.exists(dirpath)
    if not isExists:
        os.mkdir(dirpath)
        file = open(filepath, 'w')
        file.close()

