#include "StudentTicket.h"

StudentTicket::StudentTicket(): Ticket()
{}

StudentTicket::StudentTicket(const char* name, double price):Ticket(name,price / 2)
{
}
