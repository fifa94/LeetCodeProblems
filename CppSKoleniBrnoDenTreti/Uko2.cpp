#include <iostream>
#include <string>
#include <optional>
#include <vector>

class User
{
private:
    int id;
    std::string name;

public:
    User(int id, std::string name) : id(id), name(name) {}
    ~User() {}
};

template <typename T>
class Storage
{
private:
public:
    Storage() {}

    virtual void store(T *) = 0;                // C create
    virtual std::optional<T *> get(int id) = 0; // R read
                                                /*
                                                virtual void update(int, T &) = 0;       // U update
                                                */
    virtual void remove(int) = 0;               // D delete
};

template <typename V>
class MemoryStorage : public Storage<V>
{
private:
    std::vector<V*> storage;

public:
    MemoryStorage(){};
    ~MemoryStorage(){};
    void store(V *) override;                // C create
    std::optional<V *> get(int id) override; // R read
                                             /*
                                             void update(int, V &) override;       // U update
                                             */
    bool remove(int) override;               // D delete
};

template <typename T>
void MemoryStorage<T>::store(T *value)
{
    this->storage.push_back(value);
}

template <typename T>
std::optional<T *> MemoryStorage<T>::get(int id)
{

    if (id < 0)
    {
        std::nullopt;
    }

    return std::optional(this->storage[id]);
};

template <typename T>
bool MemoryStorage<T>::remove(int id)
{

    if (id < 0)
    {
        return 0;
    }

    this->storage.erase(id);

    return 1;
};

int main()
{

    Storage<User> *stor = new MemoryStorage<User>();
    stor->store(new User(1, "Franta Novak"));
    auto r = stor->get(1); // vraci uzivatele
    stor->remove(1);       // vymaze uzivatele a vrati bool
    return 0;
}
// Nevim proc to nefunguje