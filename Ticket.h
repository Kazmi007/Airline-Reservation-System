#ifndef TICKET_H
#define TICKET_H

#include <iostream>

#include "Passenger.h"
#include "Flight.h"

enum TicketType {economy, business};  // Two different ticket types.

class Flight;

class Ticket {  // Class defininition for ticket objects.
public:
	Ticket() {}
	Ticket(Passenger *passenger, Flight *flight, TicketType ticketType);

    int getTicketId() const;
    Passenger *getPassenger() const;
    Flight *getFlight() const;
    TicketType getTicketType() const;
    
	friend std::ostream &operator<<(std::ostream &os, const Ticket &ticket);

private:
	int ticketId;  // Unique ticket ID.
    Passenger *passenger;  // Pointer to the passenger ticket is assigned to.
    Flight *flight;  // Pointer to the flight the ticket is for.
    TicketType ticketType;  // Type of the ticket.
};

#endif //TICKET_H
