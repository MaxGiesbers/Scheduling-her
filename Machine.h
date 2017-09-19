#pragma once

class Machine
{
private:
	const unsigned short machineID;
	unsigned short occupiedUntil;
public:
	Machine(unsigned short aMachineID, unsigned short aOccupiedUntil);
	virtual ~Machine();
	unsigned short GetMachineId() const;
	unsigned short GetOccupiedUntil() const;
	void SetOccupiedUntil(unsigned short aOccupiedUntil);
};
