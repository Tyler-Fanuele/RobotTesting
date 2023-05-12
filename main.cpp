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

    std::vector<double> point_vect = {1, 0, 0, -1.6, -1.6, 0};

    rtde_control.moveJ(point_vect); 

    rtde_control.stopScript();
    std::cout << "Script ended\n";
    return 0;
}