class Singleton {
private:
    string val;
    static Singleton *uniqueInstance;

public:

    static Singleton *getInstance() {
        if(uniqueInstance==nullptr){
            uniqueInstance=new Singleton();
        }
        return uniqueInstance;

    }

    string getValue() {
        return this->val;
    }

    void setValue(string  &value) {
        this->val=value;
    }
};
Singleton *Singleton::uniqueInstance=nullptr;
