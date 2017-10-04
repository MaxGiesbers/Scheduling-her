#include <regex>
#include "JobShop.h"

JobShop::JobShop(const std::string &anInput, unsigned short aCurrentTime)
	: input(anInput), currentTime(aCurrentTime)
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
		//sort all jobs descending and loop over machines plus jobs
		SortJobs();

		for (auto &m : machineVector)
		{
			for (auto &j : jobVector)
			{
				//if job is already done it doesn't need to be scheduled
				if (!j.AllTasksScheduled())
				{
					//check if the machine matched with the task and if the machine is not occupied
					//also check if the job is not running a task at this moment
					if (j.GetFirstUnscheduledTask().GetMachineID() == m.GetMachineID() && CheckAvailableMachines(m.GetMachineID()) &&
						currentTime >= j.GetEndTime())
					{
						//start job if it is not started yet
						if (!j.GetJobScheduled())
							j.StartJob(currentTime);

						//update the machine and job time and set the selected task as scheduled
						m.SetOccupiedUntil(currentTime + j.GetFirstUnscheduledTask().GetTaskDuration());
						j.ScheduleTask(j.GetFirstUnscheduledTask().GetTaskID(), j.GetFirstUnscheduledTask().GetTaskDuration() + currentTime);

						break;
					}
				}
			}
		}
		++currentTime;
	}
	PrintResults();
}

void JobShop::SortJobs()
{
	std::sort(jobVector.begin(), jobVector.end(),
			  [](const Job &a, const Job &b) {
				  return a.GetTotalJobTime() > b.GetTotalJobTime() ||
						 (a.GetTotalJobTime() == b.GetTotalJobTime() && a.GetJobID() < b.GetJobID());
			  });
}

bool JobShop::CheckAvailableMachines(unsigned short machineNumber) const
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
	return std::all_of(jobVector.begin(), jobVector.end(),
					   [](const Job &j) { return j.AllTasksScheduled() == true; });
}

void JobShop::ParseJobsConfig()
{
	input.append("\n");
	std::regex rgx(".*\r?\n");
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
			break;
		}
		++matches;
		++regexIterator;
	}
}

void JobShop::PrintResults()
{
	std::sort(jobVector.begin(), jobVector.end(), [](const Job &a, const Job &b) {
		return a.GetJobID() < b.GetJobID();
	});

	for (Job &j : jobVector)
	{
		std::cout << j.GetJobID() << "\t" << j.GetStartTime() << "\t" << j.GetEndTime() << std::endl;
	}
}