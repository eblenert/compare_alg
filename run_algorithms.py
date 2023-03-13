import subprocess

# make sure all the executables are built
subprocess.run(["cmake", "-S", "algorithms_in_c",
               "-B", "build", "-G", "Unix Makefiles"])
subprocess.run(["make"], cwd="./build")


# run all sizes on all sorting algs

sizes = [1000, 10000, 50000, 100000, 500000, 1000000, 10000000, 50000000]
slow_algorithms = ['selection_sort', 'bubble_sort', 'insertion_sort']
algorithms = ['selection_sort', 'bubble_sort', 'insertion_sort',
              'merge_sort', 'quick_sort', 'heap_sort', 'radix_sort', 'shell_sort']

algorithms_execs = list(map(lambda x: f'build/{x}/{x}', algorithms))

for n in sizes:
    dataset = f'datasets/integers_list_{n}'
    for alg in algorithms:
        if alg in slow_algorithms and n > 500000:
            continue
        alg_exec = f'build/{alg}/{alg}'
        output = subprocess.check_output(
            alg_exec + ' ' + dataset, shell=True, )
        print(output.decode())
