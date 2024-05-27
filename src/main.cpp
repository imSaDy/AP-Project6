#include "global_stuff.hpp"
#include "IOhandler.hpp"

int main(int argc ,char* arg[]){
    Input iohandler(arg) ; 
    iohandler.read_input() ;
    return 0 ; 
}