#include "global_stuff.hpp"
#include "file_reader.hpp"

class Input{
public:
    Input(string) ;
    void build_tokens(); 
    vector <string> get_tokens(); 
    vector <string> get_text_parts(); 
private:
    string line ; 
    vector <string> tokens ; 
}; 
