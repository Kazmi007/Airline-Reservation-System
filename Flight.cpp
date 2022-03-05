#include "Flight.h"
using namespace std;

Flight::Flight(const std::string &flightCode, const std::string &departureTime, const std::string &arrivalTime, const std::string &departureCity, const std::string &arrivalCity, int economyCapacity, int businessCapacity) {  // Custom constructor.
    this->flightCode = flightCode;
    this->departureTime = departureTime;
    this->arrivalTime = arrivalTime;
    this->departureCity = departureCity;
    this->arrivalCity = arrivalCity;
    this->economyCapacity = economyCapacity;
    this->businessCapacity = businessCapacity;
    this->completed = false;
}

const std::string &Flight::getFlightCode() const { 
    return flightCode;
}

const std::string &Flight::getDepartureTime() const {
    return departureTime;
}

const std::string &Flight::getArrivalTime() const {
    return arrivalTime;
}

const std::string &Flight::getDepartureCity() const {
    return departureCity;
}

const std::string &Flight::getArrivalCity() const {
    return arrivalCity;
}

int Flight::getEconomyCapacity() const {
    return economyCapacity;
}

int Flight::getBusinessCapacity() const {
    return businessCapacity;
}

bool Flight::isCompleted() const {  // Returns whether the flight has been completed or not.
    return completed;
}

void Flight::setCompleted(bool completed) {  // Sets whether the flight has been completed or not.
    this->completed = completed;
}

bool Flight::addTicket(const Ticket &ticket) {  // Adds the given ticket as a new ticket in the ticket list (if capacity allows).
    if (ticket.getTicketType() == economy) {
        int cap = 0;
        for (int i = 0; i < tickets.size(); i++) 
            if (tickets[i].getTicketType() == economy)
                cap++;
        cap = economyCapacity - cap;
        if (cap) {
            tickets.push_back(ticket);
            return true;
        }
        else 
            return false;
    }
    else {
        int cap = 0;
        for (int i = 0; i < tickets.size(); i++) 
            if (tickets[i].getTicketType() == business)
                cap++;
        cap = businessCapacity - cap;
        if (cap) {
            tickets.push_back(ticket);
            return true;
        }
        else 
            return false;
    }
}

bool Flight::operator<(const Flight &rhs) const {  // Overloaded less-than operator.
    const char *s1 = &(flightCode[0]);
    const char *s2 = &(rhs.flightCode[0]);
    while (*s1 != '\0') {  // Lexicographically compares the flight codes of the two flights.
        if (*s2 == '\0' || *s2<*s1) 
            return false;
        else if (*s1 < *s2) 
            return true;
        ++s1; 
        ++s2;
    }
    return *s2 != '\0';
}

bool Flight::operator>(const Flight &rhs) const {  // Overloaded greater-than operator.
    return rhs < *this;  // Uses the overloaded less-than operator.
}

bool Flight::operator==(const Flight &rhs) const {  // Overloaded equality operator.
    return flightCode == rhs.flightCode;
}

bool Flight::operator!=(const Flight &rhs) const {  // Overloaded inequality operator.
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Flight &flight) {  // Overloaded << operator to print flight to output stream.
    os << "Flight(flightCode: " << flight.flightCode;
    os << ", departureTime: " << flight.departureTime;
    os << ", arrivalTime: " << flight.arrivalTime;
    os << ", departureCity: " << flight.departureCity;
    os << ", arrivalCity: " << flight.arrivalCity;
    os << ", economyCapacity: " << flight.economyCapacity;
    os << ", businessCapacity: " << flight.businessCapacity;
    os << ", completed: " << (flight.completed ? "yes" : "no");
    os << ", tickets: [";
    for (int i = 0 ; i < flight.tickets.size() ; ++i) {
        os << flight.tickets[i];
        if (i != (flight.tickets.size() - 1)) os << ", ";
    }
    os << "])";
    return os;
}
