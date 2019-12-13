#include "storage_types.hpp"

PackageQueue::PackageQueue(PackageQueueType type) : _type(type)
{
    if (type == PackageQueueType::FIFO)
    {
        _popFunction = [this]()->Package
        {
            Package result = _deque.front();
            _deque.pop_front();
            return result;
        };
    }
    else if (type == PackageQueueType::LIFO)
    {
        _popFunction = [this]()->Package
        {
            Package result = _deque.back();
            _deque.pop_back();
            return result;
        };
    }
}

void PackageQueue::push(Package package) { _deque.push_back(package); } //??

Package PackageQueue::pop() { return _popFunction(); }

bool PackageStockpile::empty() const { return _deque.empty(); }

size_type PackageStockpile::size() const { return _deque.size(); }