# Order-System

Design an Order System:
Company X generally processes orders based on a first come, first serve basis. Sometimes a client will ask for rush processing and will be awarded a number based on the urgency. If they pay extra they will receive a 3 priority, if they have a bulk order they will receive a 2 priority, and if they know someone in the company and ask for a favor they will receive the highest priority, a 1. Design a system that accepts orders from clients and processes these orders based on no priority or somewhere on the priority scale. Show how the system will work for random orders with a random processing time.
********************************************************************************************************************************
We need three class for the system:

class Job:

a.	This class descripts the priority, the time a job needed to be done and the time remaining for a job process.

b.	We will need a struct in order to compare two jobs based on their priority. 
(1 is the highest priority, 2 is medium priority, and 3 is the lowest priority).
********************************************************************************************************************************
class Server:

a.	The Server class is used to process a Job. We will check if the server can accept a new job, 
if so, we accept a new job and process it.

********************************************************************************************************************************
class OrderSystem:

a.	This is the main class for the order system. We will use two queues to store the job: 
a regular queue to store Jobs that have no priority (priority = 0), and a priority queue to store Jobs with priority.

b.	generateEvent(): Within probability 5%, we generate a new Job and push the job into the corresponding queue,
either has priority or no priority.

c.	processing(): This function will accept a parameter called simulation_time. 
Within the range of simulation_time, we will call generateEvent() and process the Job that we generated. 
We will need to process the Jobs that are in the priority queue first. If the priority queue is empty, 
then we process the Jobs that are in the regular queue.

d.	It is possible that we still have some Jobs left in the queues when the simulation_time is over.
We will print out those Jobs in order to see how many Jobs are not done yet.

