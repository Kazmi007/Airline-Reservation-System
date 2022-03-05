#ifndef AIRLINERESERVATIONSYSTEM_H
#define AIRLINERESERVATIONSYSTEM_H

#include "BST.h"
#include "Queue.h"
#include "Passenger.h"
#include "Flight.h"
#include "Ticket.h"

class AirlineReservationSystem {  // Class definition for the the airline reservation system.
public:
    AirlineReservationSystem() {}

    void addPassenger(const std::string &firstname, const std::string &lastname);

    Passenger *searchPassenger(const std::string &firstname, const std::string &lastname);

    void addFlight(const std::string &flightCode, const std::string &departureTime, const std::string &arrivalTime, const std::string &departureCity, const std::string &arrivalCity, int economyCapacity, int businessCapacity);

    std::vector<Flight *> searchFlight(const std::string &departureCity, const std::string &arrivalCity);

    void issueTicket(const std::string &firstname, const std::string &lastname, const std::string &flightCode, TicketType ticketType);

    void saveFreeTicketRequest(const std::string &firstname, const std::string &lastname, const std::string &flightCode, TicketType ticketType);

    void executeTheFlight(const std::string &flightCode);

    void print() const;

private: 
    BST<Passenger> passengers;  // BST containing all the passengers.
    BST<Flight> flights;  // BST containing all the flights.

    Queue<Ticket> freeTicketRequests;  // Queue containing all the free ticket requests.
};

#endif //AIRLINERESERVATIONSYSTEM_H
