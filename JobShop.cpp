#include "JobShop.h"
#include "Machine.h"

JobShop::JobShop(unsigned short aCurrentTime) :
	currentTime(aCurrentTime)
{
}

bool JobShop::checkAvailableMachines(unsigned short machineNumber)
{
	for(auto m : machineVector)
	{
		if (m.GetMachineId() == machineNumber && m.GetOccupiedUntil() <= currentTime)
		{
			return true;
		}
	}
	return false;
}

void JobShop::SortJobs()
{
	std::sort(jobVector.begin(), jobVector.end(), [](Job& a, Job& b) -> bool
	{
		return a.ReturnTotalTime() < b.ReturnTotalTime();
	});
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
