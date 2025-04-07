#pragma once

#include <benchmark/benchmark.h>
#include <regex>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

#include "utils/logger/color.hh"

/**
 * @brief Custom output class for the quicksort and mergesort algorithms benchmarks.
 * Modify the output so we can compare values to each other easier
 */
class GenericGroupingReporter : public benchmark::ConsoleReporter {
public:
    using benchmark::ConsoleReporter::ConsoleReporter;

    struct Entry {
        double real_time;
        double cpu_time;
        int iterations;
    };

    struct Row {
        std::map<std::string, Entry> by_structure;
    };

    using Key = std::pair<std::string, std::string>;  // (Algo, Type)
    std::map<Key, Row> grouped;

    void ReportRuns(const std::vector<benchmark::BenchmarkReporter::Run>& reports) override {
        std::regex pattern(R"(BM_(\w+?)_(\w+?)_(\w+))");

        for (const auto& run : reports) {
            std::smatch match;
            std::string name = run.benchmark_name();
            if (std::regex_match(name, match, pattern)) {
                std::string structure = match[1];
                std::string algo = match[2];
                std::string type = match[3];

                Entry entry;
                entry.real_time = run.real_accumulated_time;
                grouped[{algo, type}].by_structure[structure] = entry;
            }
        }
    }

    void Finalize() {
        std::set<std::string> all_structures;
        std::set<std::string> all_types;
        std::set<std::string> all_algos;
        for (const auto& [key, row] : grouped) {
            const auto& [algo, type] = key;
            all_types.insert(type);
            all_algos.insert(algo);
            for (const auto& [structure, _] : row.by_structure) {
                all_structures.insert(structure);
            }
        }

        std::map<std::pair<std::string, std::string>, double> max_time_algo_structure;
        std::map<std::pair<std::string, std::string>, double> max_time_type_structure;

        for (const auto& [key, row] : grouped) {
            const auto& [algo, type] = key;
            for (const auto& [structure, e] : row.by_structure) {
                auto algo_key = std::make_pair(algo, structure);
                auto type_key = std::make_pair(type, structure);
                max_time_algo_structure[algo_key] = std::max(max_time_algo_structure[algo_key], e.real_time);
                max_time_type_structure[type_key] = std::max(max_time_type_structure[type_key], e.real_time);
            }
        }

        const int col_algo = 0;
        const int col_type = 20;
        const int col_data_start = 40;
        const int col_width = 20;

        std::cout << BOLD;
        std::cout << std::setw(col_type - col_algo) << std::left << "Algo"
                  << std::setw(col_data_start - col_type) << "List Sorting";

        for (const auto& s : all_structures) {
            std::cout << std::setw(col_width) << s;
        }
        std::cout << "\n";
        std::cout << std::string(col_data_start + col_width * all_structures.size(), '-') << "\n";
        std::cout << RESET;

        for (const auto& [key, row] : grouped) {
            const auto& [algo, type] = key;
            std::cout << BOLD
                      << std::setw(col_type - col_algo) << std::left << algo
                      << std::setw(col_data_start - col_type) << type
                      << RESET;

            for (const auto& s : all_structures) {
                auto it = row.by_structure.find(s);
                if (it != row.by_structure.end()) {
                    const auto& e = it->second;
                    std::string color = "";
                    std::ostringstream out;
                    out << std::fixed << std::setprecision(3) << e.real_time << " s";
                    std::cout << color << std::setw(col_width) << out.str() << RESET;
                } else {
                    std::cout << std::setw(col_width) << "-";
                }
            }
            std::cout << "\n";
        }
    }
};
