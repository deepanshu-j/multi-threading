from multiprocessing import Process
import os
from random import randrange
import time

def func(n=100):
    for i in range(1,n+1):
        # time.sleep(0.01)
        print(i)
    print("function ends")
    
processes = []
num_processes = os.cpu_count() 
print(f"Total Cores in the CPU: {num_processes}")

# create processes
for i in range(num_processes):
    p = Process(target = func)
    processes = processes + [p]
    
# staring the processes

for p in processes:
    p.start()


# Join 
for p in processes:
    p.join()

# We will reach this point when all the processes are done #
print("Program ends ;D")


# Also during the execution 5 new processes will be made 
# 1 Main Process and 4 worker processes (assuming 4 cores)