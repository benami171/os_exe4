#include "Singleton.hpp"

Singleton* Singleton::instance = nullptr;
pthread_mutex_t Singleton::mutex =PTHREAD_MUTEX_INITIALIZER;

Singleton* Singleton::getInstance(){
    pthread_mutex_lock(&Singleton::mutex);
    if (Singleton::instance == nullptr){
        Singleton::instance = new Singleton();
    }
    pthread_mutex_unlock(&Singleton::mutex);
    return Singleton::instance;
}
void Singleton::destroyInstance(){
    pthread_mutex_lock(&Singleton::mutex);
    delete Singleton::instance;
    Singleton::instance = nullptr;
    pthread_mutex_unlock(&Singleton::mutex);
}

int main() {

    Singleton *sigel = Singleton::getInstance();
    Singleton::destroyInstance();

}