#include "Machine.h"
#include <iostream>

Machine::Machine(unsigned short aMachineID, unsigned short anOccupiedUntil)
:machineID(aMachineID), occupiedUntil(anOccupiedUntil)
{
}

Machine::~Machine()
{
}

unsigned short Machine::GetMachineID() const
{
	return machineID;
}

unsigned short Machine::GetOccupiedUntil() const
{
	return occupiedUntil;
}

void Machine::SetOccupiedUntil(unsigned short anOccupiedUntil)
{
	occupiedUntil = anOccupiedUntil;
}