# Airline-Reservation-System
This project features an airline reservation system that utilizes a custom binary search tree implementation and OOP.

1.1 In project, the first thing implemented is a binary search tree data structure, in which each
node will contain the data and two pointers to the root nodes of its left and right subtrees. The binary search tree
data structure will include a single pointer that points to the root node of the binary search tree. The details of the
structure are explained further in the following sections. Then, you this specialized binary search tree structure is used
to implement an airline reservation system.


--**Binary Search Tree Implementation **
The binary search tree data structure used in this project is implemented as the class template BST with the template
argument T, which is used as the type of the data stored in the nodes. The node of the binary search tree is implemented
as the class template BSTNode with the template argument T, which is the type of the data stored in nodes. BSTNode
class is the basic building block of the BST class. BST class has a single BSTNode pointer in its private data field (namely
root) which points to the root node of the binary search tree.

The BST class has its definition and implementation in BST.h file and the BSTNode class has its in BSTNode.h file.

2.1 BSTNode
BSTNode class represents nodes that constitute binary search trees. A BSTNode keeps two pointers (namely left and
right) to the root nodes of its left and right subtrees, and a data variable of type T (namely data) to hold the data. The
class has two constructors and the overloaded output operator.

2.2 BST
BST class implements a binary search tree data structure with the root pointer. Previously, data members of BST class
have been briefly described. Their use will be elaborated in the context of utility functions discussed in the following
subsections.

2.2.1 BST();
This is the default constructor. Necessary initializations are made.

2.2.2 BST(const BST<T> &obj);
This is the copy constructor. Necessary initializations are made, creating new nodes by copying the nodes in the
given obj, and inserting those new nodes into the binary search tree. The structure among the nodes in the given obj is
also be copied to the binary search tree.

2.2.3 ∼BST();
This is the destructor. Deallocates all the memory that was allocated before.
  
2.2.4 BSTNode<T> *getRoot() const;
This function returns a pointer to the root node of the binary search tree. If the binary search tree is empty, it returns NULL.

2.2.5 bool isEmpty() const;
This function returns true if the binary search tree is empty (i.e., there exists no nodes in the binary search tree).
If the binary search tree is not empty, it returns false.

2.2.6 bool contains(BSTNode<T> *node) const;
This function returns true if the binary search tree contains the given node (i.e., any root/left/right in the
binary search tree matches with node). Otherwise, it returns false.

2.2.7 void insert(const T &data);
Creates a new node with the given data and insert it at the appropriate location in the binary search tree. It should not be
asked to insert duplicated elements into the binary search tree.

2.2.8 void remove(const T &data);
Removes the node with the given data from the binary search tree. There should be no duplicated
elements in the binary search tree.

2.2.9 void removeAllNodes();
Removes all nodes of the binary search tree so that the binary search tree becomes empty.

2.2.10 BSTNode<T> *search(const T &data) const;
Searches the binary search tree for the node that has the same data with the given data and returns a pointer
to that node. If there exists no such node in the binary search tree, it returns NULL. There should be no duplicate
elements in the binary search tree.

2.2.11 BSTNode<T> *getSuccessor(BSTNode<T> *node, TraversalPlan tp) const;
Given a traversal plan (inorder, preorder or postorder) as parameter (namely tp), this function returnw a pointer
to the successor node of the given node with respect to the given traversal plan. TraversalPlan is an enumerated type
defined in BST.h file with values inorder, preorder and postorder, which are the possible methods of traversals in
binary search trees. If there exists no successor node (i.e., the given node is the last node), it returns NULL.

2.2.12 void print(TraversalPlan tp=inorder) const;
Given a traversal plan (inorder, preorder or postorder) as parameter (namely tp), this function prints the binary
search tree by traversing the nodes accordingly. 

2.2.13 BST<T> &operator=(const BST<T> &rhs);
This is the overloaded assignment operator. Removes all nodes of the binary search tree and then,
creates new nodes by copying the nodes in the given rhs and inserts those new nodes into the binary search tree. The
structure among the nodes in given rhs is also copied to the binary search tree.
  

--**Airline Reservation System Implementation **
The airline reservation system in this project is implemented as the class AirlineReservationSystem. AirlineReservationSyclass
has two BST objects in its private data field (namely passengers and flights) with the types Passenger and Flight,
respectively. These two BST objects keep the passengers and flights in the airline reservation system. Passenger class
represents the passengers in the airline reservation system. Ticket class represent the tickets issued for the passengers
by the airline. Flight class represents the flights by the airline. Tickets of a flight are kept in the flight’s corresponding
Flight object. Moreover, AirlineReservationSystem class keeps a queue of free ticket requests by the passengers in
the airline reservation system (namely freeTicketRequests).

The AirlineReservationSystem, Passenger, Ticket and Flight classes has their definitions in AirlineReservationSystem.h,
Passenger.h, Ticket.h and Flight.h files and their implementations in AirlineReservationSystem.cpp, Passenger.cpp,
Ticket.cpp and Flight.cpp files, respectively.
  
Notable functions are described below.

3.1 Passenger
Passenger objects keep firstname and lastname variables of type std::string to hold the data related with the passengers
in the airline reservation system. For this implementation, it's assumed that no two passengers will have the same
fullname (i.e., firstname + lastname).

3.1.1 bool operator<(const Passenger &rhs) const;
This is the overloaded less than comparison operator. It lexicographically compares the lastname values of
this passenger and the given passenger (rhs). If the lastname values are the same, it lexicographically compares
the firstname values of the passengers. If the compared value of this passenger is less than the given passenger’s
corresponding value, returns true. Otherwise, returns false.

3.2 Ticket
Ticket objects keep ticketId variable of type int, passenger variable of type Passenger *, flight variable of type
Flight *, and ticketType variable of type TicketType to hold the data related with the tickets in the airline reservation
system. TicketType is an enumerated type defined in Ticket.h file with values economy and business, which are the
classes for the tickets of the passengers. Passenger and Flight pointers in a Ticket are pointers to the Passenger and
Flight objects stored in the binary search trees in AirlineReservationSystem class.

 3.3 Flight
Flight objects keep flightCode, departureTime, arrivalTime, departureCity and arrivalCity variables of type
std::string, economyCapacity and businessCapacity variables of type int, and completed variable of type bool
to hold the data related with the flights in the airline reservation system. A Flight object also keeps a std::vector
of tickets to that flight (namely tickets).

3.3.1 bool addTicket(const Ticket &ticket);
This is the member function to add a new ticket to this flight. If there exists no empty seat in the asked ticket class
(economy or business), it does nothing.

3.3.2 bool operator<(const Flight &rhs) const;
This is the overloaded less than comparison operator. First, it lexicographically compare the flightCode values
of this flight and the given flight (rhs). If the compared value of this flight is less than the given flight’s corresponding
value, returns true. Otherwise, returns false.

3.4 AirlineReservationSystem
In AirlineReservationSystem class, all member functions should utilize categories member variable to operate as
described in the following subsections. 

3.4.1 void addPassenger(const std::string &firstname, const std::string &lastname);
This function adds a new passenger to the airline reservation system. It takes the passenger information (firstname
and lastname) as parameter and inserts a new Passenger object to the passengers binary search tree. If there already
exists a passenger with the same fullname, it does nothing.
  
3.4.2 Passenger *searchPassenger(const std::string &firstname, const std::string &lastname);
This function searchs for an existing passenger from the airline reservation system. It takes the firstname and lastname
of the passenger to search as parameter and returns a pointer to that Passenger object from the passengers binary
search tree. If there exists no such passenger, it return NULL.

3.4.3 void addFlight(const std::string &flightCode, const std::string &departureTime,
const std::string &arrivalTime, const std::string &departureCity,
const std::string &arrivalCity, int economyCapacity, int businessCapacity);
This function adds a new flight to the airline reservation system. It takes the flight information (flightCode, departureTime,
arrivalTime, departureCity, arrivalCity, economyCapacity and businessCapacity) as parameter and inserts a new
Flight object to the flights binary search tree. If there already exists a flight with the same flightCode, it does nothing.

3.4.4 std::vector<Flight *> searchFlight(const std::string &departureCity,
const std::string &arrivalCity);
This function searchs for the existing flights from the airline reservation system. It takes the departureCity and
arrivalCity of the flights to search as parameter and returns a std::vector of pointers to those Flight objects from
the flights binary search tree. If there exists no such passenger, it returns an empty std::vector.

3.4.5 void issueTicket(const std::string &firstname, const std::string &lastname,
const std::string &flightCode, TicketType ticketType);
This function creates a new ticket of type ticketType for the passenger with firstname and lastname to the flight with
flightCode. If there exists no such passenger or flight, it does nothing. Also, if there exists no empty seat in the flight for
the asked ticket class (economy or business), it does nothing.

3.4.6 void saveFreeTicketRequest(const std::string &firstname, const std::string &lastname,
const std::string &flightCode, TicketType ticketType);
This function creates a new free ticket request of type ticketType for the passenger with firstname and lastname to
the flight with flightCode. If there exists no such passenger or flight, it does nothing.

3.4.7 void executeTheFlight(const std::string &flightCode);
This function marks the flight with flightCode as completed. Before that, it evaluates the free ticket requests
(first come, first served) to fill the empty seats of the flight. Removes the accepted requests from the queue, and does not
change the order of the other requests. If there exists no such flight, it does nothing.


Have a safe flight :)
