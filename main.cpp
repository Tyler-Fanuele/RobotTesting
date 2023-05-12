#include <ur_rtde/rtde_control_interface.h>
#include <thread>

using namespace ur_rtde;

int main(int argc, char** argv) {
    /*
        Connect to robot with the RTDEControlInterface Constructor
    */
    std::cout << "Attempting to connect to robot\n"; 
    RTDEControlInterface rtde_control("169.254.112.14");
    std::cout << "Connected to robot\n";


    rtde_control.stopScript();
    std::cout << "Script ended\n";
    return 0;
}