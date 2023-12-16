#include <string>
#include <iostream>

class pid_controller{
    private:

    public:
        float p;
        float i;
        float d;
        float sat;

        pid_controller(float p_val, float i_val, float d_val, float sat_lim);
        float regulate(float err, int t);

        std::string get_params();
};

