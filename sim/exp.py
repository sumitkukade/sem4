import math

def generate_interval_and_binary(data,mean):
    minimum = min(data)
    maximux = max(data)
    interval = 9
    binn = (maximum-minimum)-float(interval)
    range_of_height = []
    i = 0
    while(i<maximum):
        range_of_height.append(i)
        i+=binn
    generate_frequency(range_of_height,data)
    
fin


def main():
    fd = open("")
    my_data = map(lamda x:int(x.replace(".","")),fd.readlines())
    count = len(my_data)
    data = []
    for i in range(count-1):
        data.append(my_data[i+1]-my_data[i])
    total = sum(data)
    mean = total/float(count)

    # 
    k = 10

    #ls = gen_random_variants(a,c,z0,m,n,[])
