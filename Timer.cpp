#include "Timer.h"
#include <iostream>



Timer::Timer()
{
	mSwitch = false;
	mQuit = false;
	mUpdatePeroidMs = 1000;
	mJobs.clear();
}


Timer::~Timer()
{
	mQuit = true;
	this->turnOff();
	if (mThread.joinable())
	{
		mThread.join();
		std::cout << "mThread joined." << std::endl;
	}
	else
	{
		std::cout << "mTread is unjoinable, detach it." << std::endl;
		mThread.detach();
	}
	std::cout << "Timer deleted." << std::endl;
}

void Timer::turnOn()
{
	mSwitch = true;
	if (!mThread.joinable())
	{
		mThread = std::thread([&] {
			uint16_t round = 1;
			for (;;)
			{
				if (mQuit)
				{
					std::cout << "Timer on quit." << std::endl;
					return;
				}
				if (mSwitch)
				{
					std::cout << "Job round: " << round++ << std::endl;
					for (auto j : mJobs)
					{
						j();
					}
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(mUpdatePeroidMs));
			}
		});

	}
}

void Timer::turnOff()
{
	mSwitch = false;
}

void Timer::addJob(Job job)
{
	mJobs.push_back(job);
}