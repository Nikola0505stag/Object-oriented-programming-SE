#include "GroupTicket.h"

GroupTicket::GroupTicket():Ticket()
{}

GroupTicket::GroupTicket(const char* name, double price):Ticket(name,price*0.25)
{}
