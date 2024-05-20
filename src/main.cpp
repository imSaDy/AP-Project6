#include "global_stuff.hpp"
#include "system.hpp"

int main(int argc ,char* arg[]){
    System system(arg) ; 
    system.run() ;
    return 0 ; 
}