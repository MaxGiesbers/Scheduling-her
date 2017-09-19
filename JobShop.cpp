#include "JobShop.h"
#include "Machine.h"

JobShop::JobShop(unsigned short aCurrentTime)
:currentTime(aCurrentTime)
{

	//set values in vectors.
	//Create function for setting values
}

unsigned short JobShop::GetCurrentTime() const
{
	return currentTime;
}

void JobShop::SetCurrentTime(unsigned short currentTime)
{
	this->currentTime = currentTime;
}

std::vector<Job> JobShop::GetJobVector() const
{
	return jobVector;
}

const std::vector<Machine>& JobShop::GetMachineVector() const
{
	return machineVector;
}

JobShop::~JobShop()
{
}
