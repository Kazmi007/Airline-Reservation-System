#include "Ticket.h"

Ticket::Ticket(Passenger *passenger, Flight *flight, TicketType ticketType) {  // Custom constructor.
    static int ticketId = 1;

    this->passenger = passenger;
    this->flight = flight;
    this->ticketType = ticketType;
    this->ticketId = ticketId;

    ticketId += 1;
}

int Ticket::getTicketId() const {  // Returns ticket ID.
    return ticketId;
}

Passenger *Ticket::getPassenger() const {  // Returns pointer to the passenger ticket is assigned to.
    return passenger;
}

Flight *Ticket::getFlight() const {  // Returns pointer to the flight ticket is for.
    return flight;
}

TicketType Ticket::getTicketType() const {  // Returns ticket type.
    return ticketType;
}

std::ostream &operator<<(std::ostream &os, const Ticket &ticket) {  // Overloaded << operator to print ticket to output stream.
    os << "Ticket(ticketId: " << ticket.ticketId;
    os << ", passenger: " << ticket.passenger->getFirstname() << " " << ticket.passenger->getLastname();
    os << ", flight: " << ticket.flight->getFlightCode();
    os << ", ticketType: " << (ticket.ticketType == economy ? "economy" : "business") << ")";
    return os;
}
