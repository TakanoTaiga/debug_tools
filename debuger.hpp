// Copyright 2023 Taiga Takano
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


/*
note: please copy and paste.

auto trace = t4_taiga::p_counter("");
trace.end_us();
*/


#ifndef DEBUG_TOOLS__DEBUGER_HPP_
#define DEBUG_TOOLS__DEBUGER_HPP_

#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

namespace t4_taiga{
    class p_counter{
        private:
            std::chrono::_V2::system_clock::time_point start_time;
            std::chrono::_V2::system_clock::time_point end_time;

            std::string file_path;
            std::string func_name;
        public:
        p_counter(const std::string name){
            func_name = name;
            start_time = std::chrono::high_resolution_clock::now();
        }

        template <typename T>
        void end_ms(T counter){
            end_time = std::chrono::high_resolution_clock::now();

            std::ofstream debug_csv_file;
            debug_csv_file.open("/home/taiga/Desktop/debug/" + func_name + "_milisec.csv" , std::ios::app);
            auto millisec = (double)(std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count()) / 1000;
            std::cout << millisec << " milli sec" << std::endl;
            debug_csv_file << counter << "," << millisec << std::endl;
        }

        void end_ms(){
            end_time = std::chrono::high_resolution_clock::now();

            std::ofstream debug_csv_file;
            debug_csv_file.open("/home/taiga/Desktop/debug/" + func_name + "_milisec.csv" , std::ios::app);
            auto millisec = (double)(std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count()) / 1000;
            std::cout << millisec << " milli sec" << std::endl;
            debug_csv_file << millisec << std::endl;
        }

        template <typename T>
        void end_us(T counter){
            end_time = std::chrono::high_resolution_clock::now();

            std::ofstream debug_csv_file;
            debug_csv_file.open("/home/taiga/Desktop/debug/" + func_name + "_microsec.csv" , std::ios::app);
            auto microsec = (double)(std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count()) / 1000;
            std::cout << microsec << " micro sec" << std::endl;
            debug_csv_file << counter << "," << microsec << std::endl;
        }

        void end_us(){
            end_time = std::chrono::high_resolution_clock::now();

            std::ofstream debug_csv_file;
            debug_csv_file.open("/home/taiga/Desktop/debug/" + func_name + "_microsec.csv" , std::ios::app);
            auto microsec = (double)(std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count()) / 1000;
            std::cout << microsec << " micro sec" << std::endl;
            debug_csv_file << microsec << std::endl;
        }
    };
}

#endif
