# Topics to prepare
## Thread
## STL
## Language constructs
### Memory related 
* Placement new
* Calling destructor explicitly
* Calling constructor explcicitly 
### Class related
* virtual keyword is not mandatory for child classes if method is already declared virtual in base class
* you can restrict the scope of method in child class, however since scope is resolved at compile time it will be retrieved as per pointer of class
* static member function can't be virtual
* below code is valid
``` C++
class A
{
    public:
        void print()
        {
            cout << "Hello, world";
        }
}
.
.
void main()
{
    A *a = NULL;
    a->print(); 
    /* this will give no error because we are not using any data member inside print function as we know compiler passes this as 1st parameter to memeber functions, in this case null will be passed however funtion works without side effect because none of the memebers used
    */
}

```
* sise of a class without any members is 1 byte (or compiler dependent).

## SOCKET
* sockaddr_in, sockaddr_in6
* in_addr
* htonl htons ntohl ntohs
* sockaddr_in and sockaddr are same and can be casted to one another

### TCP
#### Socket server
#### Socket clinet
### UDP
#### Socket server
#### Socket clinet
## Open SSL
### SSL Server
### SSL Client
### Hashing API
## Data structures
### Sorting
* Quick
* Heap
#### Finding nth element without sorting
## Os Concepts
### Process model
### Thread model
### Different type of memory segment
1. Code segment 
2. Data segment
3. Heap segment
### 

