n = input("n = ")
z = [None] * n
u = [None] * n
a = 5
c = 1
m = 16
m = 2 ** 32-1
z[0] = 0
k = 20 
u[0] = 0
frequency = [None] * k
frequency[0] = 0
frequencyCount = [0] * (k-1)
frequencyCount[0] = 0
for i in range(1,n):
    z[i] = ((a*z[i-1]) + c) % m 
    u[i] = float(z[i]) / m
diffrence = 1 / float(k)
print diffrence
for i in range(1,k):
    frequency[i] = frequency[i-1] + diffrence 
for i in u:
    for j in range(1,k):
        if i >= frequency[j-1] and i < frequency[j]:
            frequencyCount[j-1]+=1
sum = 0
for i in frequencyCount:
    sum += (i - (n/k)) ** 2
chi = sum*float(k)/n
print chi
