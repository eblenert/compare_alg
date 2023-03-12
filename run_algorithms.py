import subprocess

# make sure all the executables are built
subprocess.run(["cmake", "-S", "algorithms_in_c", "-B" "build"])
subprocess.run(["make"], cwd="./build")


# run all sizes on all sorting algs

sizes = [1000, 10000, 50000, 100000, 500000, 1000000, 10000000, 50000000]

datasets = map(lambda x: f'integers_list_{x}', sizes[0: 3])
algorithms = ['selection_sort', 'bubble_sort', 'insertion_sort',
              'merge_sort', 'quick_sort', 'heap_sort', 'radix_sort', 'shell_sort']

algorithms_execs = map(lambda x: f'build/x/x', algorithms)
for dataset in datasets:
    for alg in algorithms_execs:
        result = subprocess.run([alg, dataset])
        print(result)
