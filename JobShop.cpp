#include <regex>
#include "JobShop.h"
#include "Machine.h"

JobShop::JobShop(const std::string &mInput)
	: input(mInput)
{
	ParseJobsConfig();
	ParseMachinesConfig();
}

JobShop::~JobShop()
{
}

bool JobShop::checkAvailableMachines(unsigned short machineNumber)
{
	for (auto m : machineVector)
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
	std::sort(jobVector.begin(), jobVector.end(), [](Job &a, Job &b) -> bool {
		return a.ReturnTotalTime() < b.ReturnTotalTime();
	});
}

void JobShop::ParseJobsConfig()
{
	std::regex rgx("[0-9 ]+");
	std::regex_iterator<std::string::iterator> regexIterator(input.begin(), input.end(), rgx);
	std::regex_iterator<std::string::iterator> regexEnd;
	unsigned short matches = 0;

	while (regexIterator != regexEnd)
	{
		if (matches != 0)
		{
			jobVector.push_back(Job(matches - 1, regexIterator->str()));
		}
		++matches;
		++regexIterator;
	}
}

void JobShop::ParseMachinesConfig()
{
	std::regex rgx("[0-9]+");
	std::regex_iterator<std::string::iterator> regexIterator(input.begin(), input.end(), rgx);
	std::regex_iterator<std::string::iterator> regexEnd;
	unsigned short matches = 0;

	while (regexIterator != regexEnd)
	{
		if (matches == 1)
		{
			unsigned short machines = std::stoi(regexIterator->str());
			for (unsigned short i = 0; i < machines; i++)
			{
				machineVector.push_back(Machine(i, 0));
			}
		}
		++matches;
		++regexIterator;
	}
}

unsigned short JobShop::GetCurrentTime() const
{
	return currentTime;
}

void JobShop::SetCurrentTime(unsigned short aCurrentTime)
{
	currentTime = aCurrentTime;
}

const std::vector<Job> JobShop::GetJobVector() const
{
	return jobVector;
}

const std::vector<Machine> &JobShop::GetMachineVector() const
{
	return machineVector;
}

void JobShop::PrintAllConfigData()
{
	for (auto j : jobVector)
	{
		std::cout << "JobID: " << j.GetJobID() << std::endl;
		for (auto t : j.GetTaskVector())
		{
			std::cout << "TaskID: " << t.getTaskID() << " MachineID " << t.getMachineID()
					  << " TaskDuration " << t.getTaskDuration() << " TaskScheduled " << t.getTaskScheduled() << std::endl;
		}
	}

	for (auto m : machineVector)
	{
		std::cout << "MachineID " << m.GetMachineId() << " OccupiedUntil " << m.GetOccupiedUntil() << std::endl;
	}
}