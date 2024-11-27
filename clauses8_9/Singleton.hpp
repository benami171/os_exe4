#include <mutex>
#include <pthread.h>


class Singleton {
private:
    static Singleton* instance;
    static pthread_mutex_t mutex;

    Singleton(){};
    ~Singleton(){};

public:

    static Singleton* getInstance();

    static void destroyInstance();

};
