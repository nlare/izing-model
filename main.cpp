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
    Izing3D Model("Izing3D", 16, 1000, 10);

#ifndef _OPENMP
    cout << "OpenMP is not support!" << endl;
#endif

    Model.setStreams(2);
    // Model.setTemperatureStatic(4.3, 4.5, 4.7, 4.9);
    Model.setTemperatureRange(4.0, 5.0, 4.41, 4.6);
    Model.setMethod("M"); //

    omp_time_start = omp_get_wtime();

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
