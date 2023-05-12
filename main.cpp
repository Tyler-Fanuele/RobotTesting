#include <ur_rtde/rtde_control_interface.h>
#include <ur_rtde/rtde_receive_interface.h>
#include <thread>

using namespace ur_rtde;

void dump_vector(std::vector<double>& vect) {
    std::cout << "Dumping Vect: \n";
    for (auto each : vect) {
        std::cout << "  " << each << "\n";
    }
}

int main(int argc, char** argv) {
    /*
        Connect to robot with the RTDEControlInterface Constructor
    */
    std::cout << "Attempting to connect to robot\n"; 
    RTDEControlInterface rtde_control("169.254.112.14");
    RTDEReceiveInterface rtde_receive("169.254.112.14");
    std::cout << "Connected to robot\n\n";

    // Origin position
    std::vector<double> point_vect = {0, -.75, 1.75, -2.55, -1.6, 0};
    rtde_control.moveJ(point_vect); 

    // Get current pos of TCP and use this as origin from now on
    std::vector<double> init_q = rtde_receive.getActualTCPPose();

    std::vector<double> new_q = init_q;

    // X +-
    new_q[0] += .2;
    rtde_control.moveL(new_q);

    new_q[0] += -.4;
    rtde_control.moveL(new_q);

    // Return to origin
    rtde_control.moveL(init_q);
    new_q = init_q;

    // Y +-
    new_q[1] += .2;
    rtde_control.moveL(new_q);

    new_q[1] += -.4;
    rtde_control.moveL(new_q);

    // Return to origin
    rtde_control.moveL(init_q);
    new_q = init_q;

        // Y +-
    new_q[2] += .2;
    rtde_control.moveL(new_q);

    new_q[2] += -.4;
    rtde_control.moveL(new_q);

    // Return to origin
    rtde_control.moveL(init_q);
    new_q = init_q;

    // Return to slightly above origin at the end
    init_q[2] += .4;
    rtde_control.moveL(init_q);
    rtde_control.stopScript();
    std::cout << "Script ended\n";
    return 0;
}