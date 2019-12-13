#ifndef NETSIM_PACKAGE_HPP
#define NETSIM_PACKAGE_HPP

class Package {
public:
    Package();
    Package(const Package&&) = default;
    Package& operator=(const Package&&);
    ElementID get_id() const { return id; }

private:
    ElementID id;
    //static ElementID packageCounter;
};


#endif //NETSIM_PACKAGE_HPP
