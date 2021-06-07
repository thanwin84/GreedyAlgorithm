from collections import namedtuple
from operator import attrgetter
import heapq


def shortest_job_first(ids, arrival_times, burst_times):
    n = len(id)
    jobs = []
    job_attributes = ['arrival_time', 'burst_time', 'id']
    Job = namedtuple('Job', job_attributes)
    for job_details in zip(arrival_times, burst_times, ids):
        jobs.append(Job(*job_details))
    # We then first sort by arrival_time, on tie we
    # sort by burst_time, on tie we sort by id
    jobs = sorted(jobs, key=attrgetter('arrival_time', 'burst_time', 'id'))
    ready_queue = []
    heapq.heappush(ready_queue, [jobs[0].burst_time, jobs[0].id, jobs[0].arrival_time])
    i = 1  # id number
    current_time = 0
    result = []
    while ready_queue:
        top_element = heapq.heappop(ready_queue)
        result.append(top_element[1])  # appending id
        current_time += top_element[0]  # appending burst time
        while i < len(arrival_times) and jobs[i].arrival_time <= current_time:
            # python heap sort by first element
            # that's why we are pushing burst time first
            heapq.heappush(ready_queue, [jobs[i].burst_time, jobs[i].id, jobs[i].arrival_time])
            i += 1
    return result


id = [1, 2, 3, 4]
arrival = [2, 0, 4, 5]
burst = [3, 4, 2, 4]
print(shortest_job_first(id, arrival, burst))
