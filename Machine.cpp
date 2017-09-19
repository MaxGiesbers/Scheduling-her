#include "Machine.h"

Machine::Machine(unsigned short aMachineID, unsigned short aOccupiedUntil):
machineID(aMachineID), occupiedUntil(aOccupiedUntil)
{
}

unsigned short Machine::GetMachineId() const
{
	return machineID;
}

unsigned short Machine::GetOccupiedUntil() const
{
	return occupiedUntil;
}

void Machine::SetOccupiedUntil(unsigned short aOccupiedUntil)
{
	occupiedUntil = aOccupiedUntil;
}

Machine::~Machine()
{
}

