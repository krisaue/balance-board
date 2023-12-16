#include "pid_controller.h"


pid_controller::pid_controller(float p_val, float i_val, float d_val, float sat_lim){
    p = p_val;
    i = i_val;
    d = d_val;
    sat = sat_lim;
};

std::string pid_controller::get_params()
{
    std::string param_string;
    param_string ="P: "+ std::to_string(p) + " I: " + std::to_string(i) + " D: " + std::to_string(d) + "saturation limit: " +  std::to_string(sat);
    return param_string;
    //std::cout<<"p: "<<p<<" i: "<<i<<" d: "<<d<<" saturation limit: "<<sat<<"\n";
}