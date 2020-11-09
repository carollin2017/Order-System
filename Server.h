#pragma once
#include "Job.h"

class Server
{
private:
	Job* j = nullptr;
	

public:
	//Check if the server can accept a new job, meaning no job is being processed.
	bool canAcceptNewJob() {
		return j == nullptr;
	}

	//Accept a new job obj.
	void acceptNewJob(Job* obj) {
		j = obj;
		j->print_job();
	}


	void process() {
		//if the j pointer is null, then no job needs to be processed.
		if (j == nullptr) {
			return;
		}

		int time = j->timeRemaining;
		//when timeRemaining is 0, the job is done, reset the j to nullptr.
		if (time == 0) {
			j = nullptr;
		}
		//Otherwise, we decrease the timeRemaining by 1.
		else {
			j->timeRemaining--;
		}

	}

	~Server() {
		delete j;
	}
};