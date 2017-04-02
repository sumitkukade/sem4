def main():
    arrival_time = raw_input().split()
    arrival_time = list(map(float,arrival_time))
    service_time = raw_input().split()
    service_time = list(map(float,service_time))

    clock = [x*0.0 for x in range(len(arrival_time))]
    persons_go_away = [x*0 for x in range(len(arrival_time))]
    clock[0] = arrival_time[0]

    service_start_time = [x*0.0 for x in range(len(arrival_time))]
    service_start_time[0] = arrival_time[0]

    service_ends_time = [x*0.0 for x in range(len(arrival_time))]
    service_ends_time[0] = arrival_time[0] + service_time[0]
   
    waiting_times = [x*0.0 for x in range(len(arrival_time))]
    queue = [x*0 for x in range(len(arrival_time))]

    
    persons_in_q = 0
    for index in range(1,len(arrival_time)):
        clock[index] = round((clock[index-1]+arrival_time[index]),2)
        service_start_time[index] = round((service_ends_time[index-1]),2)
        service_ends_time[index] = round((service_start_time[index] + service_time[index]),2)
        waiting_times[index] = round((service_ends_time[index-1] - clock[index]),2)
        persons = 0
        for i in range(0,index):
            if clock[index] < service_ends_time[i]:
                persons+=1
        queue[index] = persons

    print "SR\tAT\tCT\tST\tSS\tSE\tWT\tQueue\tGo_away"
    for i in range(0,len(arrival_time)):
       print str(i+1),"\t",str(arrival_time[i]),"\t",str(clock[i]),"\t",service_time[i],"\t",str(service_start_time[i]),"\t",str(service_start_time[i]),"\t",waiting_times[i],"\t",str(queue[i]),"\t",persons_go_away[i]
main()
