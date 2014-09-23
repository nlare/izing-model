/*
 * izing-3d.h
 *
 *  Created on: 22 апр. 2014 г.
 *      Author: nlare
 */

#include "models.cpp"

#ifndef IZING_3D_H_
#define IZING_3D_H_

class Izing3D: public Models  {
    public:
        Izing3D(string _name, int _grid_size, int _mks_max, int _statistic);
        ~Izing3D(void);
        void ShowCharacteristicOfModel();
        void FormSourceConf(); // здесь формируем начальную конфигурацию спинов
        void SetTemperatureRange(double, double, double, double);
        void SetTemperatureRange(double, double);
        void SetTemperatureStatic(double);
        void SetTemperatureStatic(double, double, double, double);
        void SetStreams(int);
        void SetMethod(string);

        void WriteRelax();
        void WriteTdCharToFile();

        // void Relaxation(int);
        void SaveSpinConf(int);
        // void ACF(int);

        void StatisticProcessing();

        void Metropolis(double);
        void SwendsenWang(double);
        void WolfStackBased(double);
        void WolfMassiveBased(double);

        int Start();
        int PlotGraph(string);
        // void measure_only_relax();

    private:
        int ***spin, ***spin_old;

        double T_div[100];
        double T, T_min, T_max, T_dr1, T_dr2;

        struct _data_t {

            double energy_per_spin;
            double magnetic_per_spin;

            double energy;
            double magnet;
            double C_v;
            double X;

            double relax;
            double correlation;

            int old_config;
            int new_config;

            double first_correlation_mcs;
            double first_correlation_magnet;

            double sum[4];

            _data_t()    {
                energy_per_spin = 0.0;
                magnetic_per_spin = 0.0;
            }

        } data[8];

        struct _statistic_t {

            double magnet;
            double energy;

            double relax;
            double correlation;

            double error_relax[2]; // 0 element - delta = (<mcs^2> - <mcs>^2)^1/2, 1 element - <mcs^2>, 2 element - <mcs>^2
            double error_correlation[2]; // 0 element - delta = (<mcs^2> - <mcs>^2)^1/2, 1 element - <mcs^2>, 2 element - <mcs>^2

        } statistic[8];

        struct trigger_t {
            bool correlation;
            bool relax_print;
            bool relax;

            trigger_t()   {
                correlation = true;
                relax_print = true;
                relax = true;
            }
        }   trigger[8];

        string algorithm;

        double first_mcs_magnet;

        int cluster_elements;

        int streams;
        int thread_num;

        int statistic_max, mcs_max;
        int T_div_max_index;
        bool static_temp, static_procs_parallel;
        int static_procs_count;
        bool remove_relax, remove_appr, only_relax;
        char * name_relax, * name_appr, * name_temp;

        std::ofstream out_relax, out_appr;
           // out_appr - файл с аппроксимированными значениями

        void magnetic(int);
        void energy(int);

        int nearly_spins(int, int, int);
};

#endif /* IZING_3D_H_ */
