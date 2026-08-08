#ifndef CONTAINER_H
#define CONTAINER_H

class Container {
public: 
    virtual double& operator[](int) = 0;
    virtual int size() const = 0;
    virtual ~Container() {}
};

#endif // CONTAINER_H