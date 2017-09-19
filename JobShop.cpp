#include <regex>
#include "JobShop.h"
#include "Machine.h"

JobShop::JobShop(const std::string &mInput) : input(mInput)
{
	ParseJobsConfig();
	ParseMachinesConfig();
	RunSchedulingAlgorithm();
}

JobShop::~JobShop()
{
}

void JobShop::RunSchedulingAlgorithm()
{
	while (!AllJobsScheduled())
	{
		SortJobs();
		PrintAllConfigData();
		for (auto &m : machineVector)
		{
			if (checkAvailableMachines(m.GetMachineId()))
			{
				for (auto &j : jobVector)
				{

					Task currentTask = j.GetFirstUnscheduledTask();

					if (currentTask.getMachineID() == m.GetMachineId())
					{
						m.SetOccupiedUntil(currentTime + currentTask.getTaskDuration());
						j.SetTask(currentTask.getTaskID());
						j.SetJobEndTime(currentTask.getTaskDuration() + currentTime);
					}
					break;
				}
			}
		}
		currentTime++;
		std::cout << "time " << currentTime << std::endl;
	}
	PrintResults();
}

bool JobShop::checkAvailableMachines(unsigned short machineNumber)
{
	for (auto &m : machineVector)
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
	std::sort(jobVector.begin(), jobVector.end(), [](const Job &a, const Job &b) {
		return a.ReturnTotalTime() > b.ReturnTotalTime() || (a.ReturnTotalTime() == b.ReturnTotalTime() && a.GetJobId() < b.GetJobId());
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
		std::cout << "JobID: " << j.GetJobId() << std::endl;
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
bool JobShop::AllJobsScheduled() const
{

	return std::all_of(jobVector.begin(), jobVector.end(), [](const Job &j) { return j.AllTasksScheduled() == true; });
}

void JobShop::PrintResults()
{

	for (Job &j : jobVector)
	{
		std::cout << j.GetJobId() << "\t" << j.GetStartTime() << "\t" << j.GetEndTime() << std::endl;
	}
}
