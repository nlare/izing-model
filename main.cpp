/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  07.12.2013 02:54:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  nlare
 *   Organization:  univer
 *
 * =====================================================================================
 */

// #include "izing-2d.cpp"
#include "izing-3d.cpp"
//#include "izing_data.pb.h"
//#include "izing_data.pb.cc"

using namespace std;

int main(int argc, char *argv[])    {
    long omp_time_start, omp_time_end;
    
    stringstream command;

    // Izing2D Model("Izing2D", 16, 1000, 100);
    //params - name, grid_size, mcs_max, statistic
    Izing3D Model("Izing3D", 16, 1000, 25);

#ifndef _OPENMP
    cout << "OpenMP is not support!" << endl;
#endif

    // TwoDimIzingModel.set_streams(1);
   // TwoDimIzingModel.set_temperature_range(3.0, 2.35);
    // TwoDimIzingModel.set_temperature_static(3.5, 3.0, 2.5, 2.261);
    // TwoDimIzingModel.set_temperature_static(2.5);
    // TwoDimIzingModel.set_method("W");

    Model.setStreams(4);
    // Model.SetTemperatureStatic(4.3, 4.51, 4.7, 5.0);
    Model.setTemperatureRange(4.0, 5.0, 4.41, 4.6);
    Model.setMethod("M"); //

    omp_time_start = omp_get_wtime();

    // TwoDimIzingModel.start();
    if(!Model.Start())  {
        cerr << "Cannot start meshuring..." << endl;
    }

    // if(Model.PlotGraph("E"))    {
    //     cout << "End of plot." << endl;
    // }   else    {
    //     cerr << "Error, graphs not gen. " << endl;
    // }
    // Model.PlotGraph("M");
    // Model.PlotGraph("X");
    // Model.PlotGraph("C_v");

    omp_time_end = omp_get_wtime();

    cout << "Measurement time is [ OMP = " << omp_time_end - omp_time_start << " sec ]";

    getchar();

    return 0;
}
