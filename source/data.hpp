#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED



struct ProcessedData {
    double ax_max;
    double ax_min;
    double ax_std;
    double ax_peaks;
    double ax_total;

    double ay_max;
    double ay_min;
    double ay_std;
    double ay_peaks;
    double ay_total;   

    double az_max;
    double az_min;
    double az_std;
    double az_peaks;
    double az_total;
};

ProcessedData processData(double &x, double &y, double &z) {
    ProcessedData result;
    
}

#endif // DATA_HPP_INCLUDED