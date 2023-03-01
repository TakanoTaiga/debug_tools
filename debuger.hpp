#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

#define MICROSEC true
#define MILLISEC false

#define TIME_UNIT MICROSEC

namespace tieriv_taiga{
    class p_counter{
        private:
            std::chrono::_V2::system_clock::time_point start_time;
            std::chrono::_V2::system_clock::time_point end_time;

            std::string file_path;
        public:
        p_counter(const std::string funcName){
#if TIME_UNIT
            file_path = "/home/taiga/Desktop/debug/" + funcName + "_microsec.csv";
#else
            file_path = "/home/taiga/Desktop/debug/" + funcName + "_milliosec.csv";
#endif
            start_time = std::chrono::high_resolution_clock::now();
        }

        void end(uint64_t counter = 0){
            end_time = std::chrono::high_resolution_clock::now();
            auto dur = end_time - start_time;

            std::ofstream debug_csv_file;
            debug_csv_file.open(file_path , std::ios::app);
#if TIME_UNIT
            auto microsec = (double)(std::chrono::duration_cast<std::chrono::nanoseconds>(dur).count()) / 1000;
            std::cout << microsec << " micro sec" << std::endl;
            debug_csv_file << counter << "," << microsec << std::endl;
#else
            auto millisec = (double)(std::chrono::duration_cast<std::chrono::microseconds>(dur).count()) / 1000;
            std::cout << millisec << " milli sec" << std::endl;
            debug_csv_file << counter << "," << millisec << std::endl;
#endif
        }
    };
}
