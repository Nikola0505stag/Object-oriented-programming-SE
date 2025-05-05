#pragma once
#include "Ticket.h"

class StudentTicket : public Ticket
{

public:
	StudentTicket();
	StudentTicket(const char* name, double price);
	
};

