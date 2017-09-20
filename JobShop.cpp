#include <regex>
#include "JobShop.h"

JobShop::JobShop(const std::string &anInput, unsigned short aCurrentTime) : input(mInput), currentTime(aCurrentTime)
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
		//sort all jobs descending
		SortJobs();

		//PrintAllConfigData();
		for (auto &m : machineVector)
		{
			for (auto &j : jobVector)
			{
				//copy task
				Task currentTask = j.GetFirstUnscheduledTask();

				//check if the machine is available and if current job time is higher or the same as currentTime
				if (currentTask.GetMachineID() == m.GetMachineID() && CheckAvailableMachines(m.GetMachineID()) && currentTime >= j.GetEndTime() && currentTask.GetTaskDuration() != 0)
				{
					if (!j.GetJobScheduled())
					{
						//Set job startTime
						j.StartJob(currentTime);
					}

					m.SetOccupiedUntil(currentTime + currentTask.GetTaskDuration());

					//set boolean of scheduled task to true and set job endtime
					j.ScheduleTask(currentTask.GetTaskID(), currentTask.GetTaskDuration() + currentTime);

					break; //nog niet gecheck of deze weg kan...
				}
			}
		}
		currentTime++;
	}
	PrintResults();
}

void JobShop::SortJobs()
{
	std::sort(jobVector.begin(), jobVector.end(),
			  [](const Job &a, const Job &b) {
				  return a.GetTotalJobTime() > b.GetTotalJobTime() || (a.GetTotalJobTime() == b.GetTotalJobTime() && a.GetJobID() < b.GetJobID());
			  });
}

bool JobShop::CheckAvailableMachines(unsigned short machineNumber)
{
	for (auto &m : machineVector)
	{
		if (m.GetMachineID() == machineNumber && m.GetOccupiedUntil() <= currentTime)
		{
			return true;
		}
	}
	return false;
}

bool JobShop::AllJobsScheduled() const
{

	return std::all_of(jobVector.begin(), jobVector.end(), [](const Job &j) { return j.AllTasksScheduled() == true; });
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
			jobVector.push_back(Job(regexIterator->str(), matches - 1));
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

void JobShop::PrintResults()
{
	//Sort vector low to high.
	std::sort(jobVector.begin(), jobVector.end(), [](const Job &a, const Job &b) {
		return a.GetJobID() < b.GetJobID();
	});

	for (Job &j : jobVector)
	{
		std::cout << j.GetJobID() << " " << j.GetStartTime() << " " << j.GetEndTime() << std::endl;
	}
}

void JobShop::PrintAllConfigData()
{
	for (auto &j : jobVector)
	{
		std::cout << "JobID: " << j.GetJobID() << std::endl;
		for (auto &t : j.GetTaskVector())
		{
			std::cout << "TaskID: " << t.GetTaskID() << " MachineID " << t.GetMachineID() << " TaskDuration "
					  << t.GetTaskDuration() << " TaskScheduled " << t.GetTaskScheduled() << std::endl;
		}
	}

	for (auto &m : machineVector)
	{
		std::cout << "MachineID " << m.GetMachineID() << " OccupiedUntil " << m.GetOccupiedUntil()
				  << std::endl;
	}
}