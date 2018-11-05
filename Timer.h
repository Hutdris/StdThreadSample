#pragma once

#include <thread>
#include <chrono>
#include <functional>
#include <vector>

class Timer
{
public:
	typedef std::function<void(void)> Job;

	Timer();
	virtual ~Timer();
	void turnOn();
	void turnOff();
	void addJob(Job job);
private:
	std::thread mThread;
	std::vector<Job> mJobs;

	uint32_t mUpdatePeroidMs;
	bool mSwitch, mQuit;

};

