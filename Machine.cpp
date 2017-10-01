#include "Machine.h"

Machine::Machine(const unsigned short aMachineID, unsigned short anOccupiedUntil)
	: machineID(aMachineID), occupiedUntil(anOccupiedUntil)
{
}

Machine::~Machine()
{
}

Machine::Machine(const Machine &aMachine)
	: machineID(aMachine.machineID), occupiedUntil(aMachine.occupiedUntil)
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