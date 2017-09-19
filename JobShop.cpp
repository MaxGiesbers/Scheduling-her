#include <regex>
#include "JobShop.h"
#include "Machine.h"

JobShop::JobShop(const std::string &mInput) :
	input(mInput)
{
	parseJobsConfig();
	parseMachinesConfig();
}

JobShop::~JobShop()
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
		return a.ReturnTotalTime() < b.ReturnTotalTime() && a.GetJobId() < b.GetJobId();
	});
}

void JobShop::parseJobsConfig()
{
	std::regex rgx("[0-9 ]+");
	std::regex_iterator<std::string::iterator> regexIterator(input.begin(), input.end(), rgx);
	std::regex_iterator<std::string::iterator> regexEnd;
	unsigned short lineNumber = 0;

	while (regexIterator != regexEnd)
	{
		if (lineNumber != 0)
		{
			jobVector.push_back(Job(lineNumber - 1, regexIterator->str()));
		}
		++lineNumber;
		++regexIterator;
	}
}

void JobShop::parseMachinesConfig()
{
	std::regex rgx("[0-9]+");
	std::regex_iterator<std::string::iterator> regexIterator(input.begin(), input.end(), rgx);
	std::regex_iterator<std::string::iterator> regexEnd;
	unsigned short matches = 0;

	while (regexIterator != regexEnd)
	{
		if (matches != 0)
		{
			int machines = std::stoi(regexIterator->str());
			for(unsigned short i = 0; i < machines; i++)
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

bool JobShop::AllJobsScheduled() const
{

	return std::all_of(jobVector.begin(), jobVector.end(), [](const Job& j)
	{	return j.AllTasksScheduled() == true;});
}

void JobShop::PrintResults(){

	for(Job &j : jobVector)
	{
		std::cout << j.GetJobId() << " " << j.GetStartTime() << " " << j.GetEndTime() << std::endl;
	}
}
