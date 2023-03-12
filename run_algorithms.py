import subprocess

# make sure all the executables are built
subprocess.run(["cmake", "-S", "algorithms_in_c", "-B" "build"])


# run all sizes on all sorting algs

sizes = [1000, 10000, 50000, 100000, 500000, 1000000, 10000000, 50000000]
datasets = map(lambda x: f'integers_list_{x}', sizes)

for dataset in datasets:
    print(dataset)