#include "Timer.h"
#include <iostream>

void timerTest()
{
	Timer clock;

	clock.addJob(Timer::Job([]() {std::cout << "Coding..." << std::endl; }));
	clock.addJob(Timer::Job([]() {std::cout << "Reading..." << std::endl; }));

	clock.turnOn();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	clock.turnOff();
	clock.turnOff();
}
int main()
{
	timerTest();
	system("pause");
	return 0;
}