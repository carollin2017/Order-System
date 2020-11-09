#pragma once
#include <queue>
#include <iostream>
#include <string>
#include <time.h>
#include <iostream>
#include "Job.h"
#include "Server.h"
using namespace std;

class OrderSystem 
{
private:
	queue<Job *> regular;
	priority_queue<Job *, vector<Job *>, CompareJob> premium;
	Server* server;
	
public:
	OrderSystem() {
		server = new Server();
	}

	void generateEvent() {
		//Randomly generate priority 0, 1, 2, 3 and put Jobs into the corresponding queue.
		if (rand() % 100 < 5) {
			int num = rand() % 4;
			Job* job = new Job(num);
			job->getProcessingTime();
			if (num == 0) {
				regular.push(job);
			}
			else {
				premium.push(job);
			}
		}
	}

	void processing(int simulation_time) {
		for (int i = 1; i <= simulation_time; i++) {
			generateEvent();
			server->process();
			if (server->canAcceptNewJob()) {
				//Process jobs in the premium queue first, if premium queue is empty,
				//then process the regular queue.
				if (!premium.empty()) {
					server->acceptNewJob((Job *)premium.top());
					premium.pop();
				}
				else {
					if (!regular.empty()) {
						server->acceptNewJob(regular.front());
						regular.pop();
					}
				}
				
				
			}
		}

		cout << "unprocessed:" << endl;
		while (!premium.empty()) {
			premium.top()->print_job();
			premium.pop();
		}
	}

	~OrderSystem() {
		delete server;
	}



};
