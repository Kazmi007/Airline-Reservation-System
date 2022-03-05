#include "AirlineReservationSystem.h"

void AirlineReservationSystem::addPassenger(const std::string &firstname, const std::string &lastname) {  // Adds a new passenger with the given first and last name to the system.
    Passenger p(firstname, lastname);
    if (!passengers.search(p))
        passengers.insert(p);
}

Passenger *AirlineReservationSystem::searchPassenger(const std::string &firstname, const std::string &lastname) {  // Returns pointer to the passenger with the given name.
    Passenger p(firstname, lastname);
    return &(passengers.search(p)->data);
}

void AirlineReservationSystem::addFlight(const std::string &flightCode, const std::string &departureTime, const std::string &arrivalTime, const std::string &departureCity, const std::string &arrivalCity, int economyCapacity, int businessCapacity) {  // Adds a new flight with the given data to the system.
    Flight f(flightCode, departureTime, arrivalTime, departureCity, arrivalCity, economyCapacity, businessCapacity);
    if (!flights.search(f))
        flights.insert(f);
}

std::vector<Flight *> AirlineReservationSystem::searchFlight(const std::string &departureCity, const std::string &arrivalCity) {  // Returns a list of the flights between the given cities.
    std::vector<Flight *> f;
    BSTNode<Flight> *node = flights.getRoot();
    while (node) {
        if ((node->data.getDepartureCity() == departureCity) && (node->data.getArrivalCity() == arrivalCity))
            f.push_back(&(node->data));
        node = flights.getSuccessor(node, preorder);
    }
    return f;
}

void AirlineReservationSystem::issueTicket(const std::string &firstname, const std::string &lastname, const std::string &flightCode, TicketType ticketType) {  // Issues a new ticket with the given data for the given flight.
    Passenger p(firstname, lastname);
    Flight f(flightCode, "", "", "", "", 0, 0);
    if (passengers.search(p) && flights.search(f)) {
        BSTNode<Passenger> *ps = passengers.search(p);
        BSTNode<Flight> *fl =  flights.search(f);
        Ticket t(&(ps->data), &(fl->data), ticketType);
        fl->data.addTicket(t);
    }
}

void AirlineReservationSystem::saveFreeTicketRequest(const std::string &firstname, const std::string &lastname, const std::string &flightCode, TicketType ticketType) {  // Creates a new free ticket request with the given data.
    Passenger p(firstname, lastname);
    Flight f(flightCode, "", "", "", "", 0, 0);
    if (passengers.search(p) && flights.search(f)) {
        BSTNode<Passenger> *ps = passengers.search(p);
        BSTNode<Flight> *fl =  flights.search(f);
        Ticket t(&(ps->data), &(fl->data), ticketType);
        freeTicketRequests.enqueue(t);
    }
}

void AirlineReservationSystem::executeTheFlight(const std::string &flightCode) {  // Executes the flight (after filling the empty seats with free tickets).
    Flight f(flightCode, "", "", "", "", 0, 0);
    if (flights.search(f)) {
        BSTNode<Flight> *fl =  flights.search(f);
        Queue<Ticket> q;
        while (!freeTicketRequests.isEmpty()) {
            Ticket t = freeTicketRequests.dequeue();
            if (t.getFlight()->getFlightCode() == flightCode) {
                if (!(fl->data.addTicket(t)))
                    q.enqueue(t);
            }
            else
                q.enqueue(t);
        }
        while (!q.isEmpty())
            freeTicketRequests.enqueue(q.dequeue());
        fl->data.setCompleted(true);
    }
}

void AirlineReservationSystem::print() const {  // Prints the system state.
    std::cout << "# Printing the airline reservation system ..." << std::endl;

    std::cout << "# Passengers:" << std::endl;
    passengers.print(inorder);

    std::cout << "# Flights:" << std::endl;
    flights.print(inorder);

    std::cout << "# Free ticket requests:" << std::endl;
    freeTicketRequests.print();

    std::cout << "# Printing is done." << std::endl;
}
