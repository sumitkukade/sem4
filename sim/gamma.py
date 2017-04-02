from math import ceil,exp
import matplotlib.pyplot as plt

def get_frequency(data):
    interval = 10
    intervals = []
    bin = (max(data)-min(data))/interval
    #print max(data),min(data)
    interval_list = []
    for x in range(interval):
        interval_list.append(0)
    for x in range(interval):
        interval_list[x] = interval_list[x-1]+bin
    
    for i in range(interval-1):
        intervals.append(len(filter(lambda x: x>=interval_list[i] and x< interval_list[i+1],data)))
    intervals.append(1)
    return intervals, interval_list

def draw_plot(frequency, interval, bean_size):
    plt.bar(interval,frequency, width=bean_size)
    plt.plot()
    plt.show()

f = open("2.csv",'r')

my_data = map(lambda x:float(x),f.readlines())
count = len(my_data)
mean = sum(my_data)/float(count)
variance = sum(map(lambda x:(x-mean)**2,my_data))/float(count)

bita = variance/float(mean)
alfa = ceil(mean/float(bita))
frequency, interval = get_frequency(my_data)
print len(frequency), len(interval)
draw_plot(frequency, interval, 5) 

# calc expeted frequecy
# probablity adjustement
# kai square test



