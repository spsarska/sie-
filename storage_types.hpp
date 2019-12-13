#ifndef NETSIM_STORAGE_TYPES_HPP
#define NETSIM_STORAGE_TYPES_HPP

#include "package.hpp"
#include "types.hpp"
#include <deque>
#include <functional>


enum class PackageQueueType {
    FIFO, LIFO
};


class IPackageStockpile {
public:
    virtual void push(Package&&) = 0; //void push(Package);  ??
    virtual bool empty() = 0;
    virtual size_type size() = 0;
    //Interfejs IPackageStockpile powinien posiadać metodę do umieszczania półproduktu na składowisku
    // oraz metody pozwalające na uzyskanie dostępu “tylko do odczytu” do kontenera przechowującego półprodukty (tj. metody [c]begin(), [c]end() – łącznie 4 metody).
};


class IPackageQueue : public IPackageStockpile {
public:
    virtual Package pop() = 0;
    virtual PackageQueueType get_queue_type() = 0;
    //metoda do “wyciągania” półproduktu (tj. jego usuwanie z kolejki wraz ze zwracaniem)
    // metodę identyfikującą typ kolejki (LIFO/FIFO).
};


class PackageQueue : public IPackageQueue {
public:
    PackageQueue(PackageQueueType);
    void push(Package&&); //void push(Package);  ??
    bool empty();
    size_type size();
    Package pop();
    PackageQueueType get_queue_type() const { return queuetype; }
private:
    PackageQueueType _type;
    std::deque<Package> _deque;
    std::function<Package()> _popFunction;
};


#endif //NETSIM_STORAGE_TYPES_HPP
