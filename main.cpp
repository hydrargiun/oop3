#include <iostream>
#include "dialog.h"
#include "getnum.h"



using namespace oop3;
int main() {


        try {
            dialog();


        }
            catch (std::bad_alloc &ba) {
                std::cout << "Error in allocating memory: " << ba.what() << std::endl;
            }
            catch (std::exception &ex) {
                std::cout << "Exception detected: " << ex.what() << std::endl;
            }
            catch (...) {
                std::cout << "Unknown error occured!" << std::endl;
            }

    return 0;
}
