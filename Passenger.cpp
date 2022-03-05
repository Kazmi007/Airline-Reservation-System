#include "Passenger.h"

Passenger::Passenger(std::string firstname, std::string lastname) {  // Custom constructor.
    this->firstname = firstname;
    this->lastname = lastname;
}

const std::string &Passenger::getFirstname() const {  // Returns first name of the passenger.
    return firstname;
}

const std::string &Passenger::getLastname() const {  // Returns last name of the passenger.
    return lastname;
}

bool Passenger::operator<(const Passenger &rhs) const {  // Overloaded less-than operator
    if (lastname != rhs.lastname) {  // Lexicographically compares the last names first.
        const char *s1 = &(lastname[0]);
        const char *s2 = &(rhs.lastname[0]);
        while (*s1 != '\0') {
            if (*s2 == '\0' || *s2<*s1) 
                return false;
            else if (*s1 < *s2) 
                return true;
            ++s1; 
            ++s2;
        }
        return *s2 != '\0';
    }
    else {  // If last names are equal then lexicographically compares first names.
        const char *s1 = &(firstname[0]);
        const char *s2 = &(rhs.firstname[0]);
        while (*s1 != '\0') {
            if (*s2 == '\0' || *s2<*s1) 
                return false;
            else if (*s1 < *s2) 
                return true;
            ++s1; 
            ++s2;
        }
        return *s2 != '\0';
    }
}

bool Passenger::operator>(const Passenger &rhs) const {  // Overloaded greater-than operator
    return rhs < *this;  // Uses the overloaded less-than operator.
}

bool Passenger::operator==(const Passenger &rhs) const {  // Overloaded equality operator.
    return firstname == rhs.firstname && lastname == rhs.lastname;
}

bool Passenger::operator!=(const Passenger &rhs) const {  // Overloaded inequality operator.
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Passenger &passenger) {  // Overloaded << operator to print passenger to output stream.
    os << "Passenger(firstname: " << passenger.firstname;
    os << ", lastname: " << passenger.lastname << ")";
    return os;
}
