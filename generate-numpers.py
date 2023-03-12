import os
from string import Template
from numpy.random import default_rng

rng = default_rng()

list_sizes = [1000, 10000, 50000, 100000, 500000, 1000000, 10000000, 50000000]
filenameTemplate = Template('datasets/integers_list_$nr')

if not os.path.isdir("datasets"):
    os.makedirs("datasets")

for nr in list_sizes:
    filename = filenameTemplate.substitute(nr=nr)

    numbers = list(range(0, nr, 1))
    rng.shuffle(numbers)
    with open(filename, 'w') as file:
        file.write(str(nr) + '\n')
        for number in numbers:
            file.write(str(number) + '\n')
        print(f'Finished file with {nr} numbers\n')
