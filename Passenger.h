#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>

class Passenger {  // Class definition for passenger objects.
public:
    Passenger() {}
    Passenger(std::string firstname, std::string lastname);

    const std::string &getFirstname() const;
    const std::string &getLastname() const;

    bool operator<(const Passenger &rhs) const;
    bool operator>(const Passenger &rhs) const;
    bool operator==(const Passenger &rhs) const;
    bool operator!=(const Passenger &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Passenger &passenger);

private:  // Holds the first and last name of the passenger.
    std::string firstname;  
    std::string lastname;
};

#endif //PASSENGER_H
