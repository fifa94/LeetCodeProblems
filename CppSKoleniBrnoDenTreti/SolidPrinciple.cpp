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
    User(int, std::string &);
    ~User();
    int get_id();
    void set_id(int id);
    void set_name(std::string &);
};

User::User(int, std::string &)
{
    
}

User::~User()
{
}

// Interface
class Storage
{
private:
    
public:
    Storage(/* args */);
    virtual ~Storage();
    virtual void store(User &) = 0;             // C create
    virtual std::optional<User &> get(int) = 0; // R read
    virtual void update(int, User &) = 0;       // U update
    virtual void remove(int) = 0;               // D delete
};

Storage::Storage(/* args */)
{
}

Storage::~Storage()
{
}

class MemoryStorage : public Storage
{
private:
    std::vector<User> database;

public:
    MemoryStorage(/* args */);
    ~MemoryStorage();
    void store(User &) override;             // C create
    std::optional<User &> get(int) override; // R read
    void update(int, User &) override;       // U update
    void remove(int) override;               // D delete
};

MemoryStorage::MemoryStorage(/* args */)
{
}

MemoryStorage::~MemoryStorage()
{
}

class UserDatabase
{
private:
    Storage* storage;

public:
    UserDatabase(Storage* storage);
    ~UserDatabase();
};

UserDatabase::UserDatabase(Storage* storage): storage(storage){

}

UserDatabase::~UserDatabase(){

    
}

int main()
{
    // dependeci injection
    MemoryStorage* memory_db;
    UserDatabase db(memory_db);
}