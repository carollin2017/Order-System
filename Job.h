#pragma once
#include <time.h>
#include <iostream>
using namespace std;

class Job 
{
public:
	int processingTime;
	int timeRemaining;
	int priority;

	Job(int p) {
		priority = p;
	}

	void print_job() const {
		cout << "The priority of the job is " << priority << "; processing time is " << processingTime << endl;
	}

	void getProcessingTime() {
		//Assume that processingTime won't exceed 40, randomly generate the processingTime.
		processingTime = rand() % 40 + 1;
		timeRemaining = processingTime;
		
	}

};


//Compare two jobs by their priority.
struct CompareJob {
	bool operator()(Job * j1, Job * j2) {
		return j1->priority > j2->priority;
	}
};

