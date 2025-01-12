// Created: 2025-01-11 21:57 GMT+2
// Modified: 2025-01-11 21:57 GMT+2
// (c) 2025 @Silicon27
// This source code is licensed under the MIT license (see LICENSE for details)
// MCPP - Collections of C++ utilities for various purposes

#ifndef MCPP_H
#define MCPP_H

#include <iostream>


namespace mcpp {
    namespace io {
        // Input/Output functions

        // Print function for all types
        template <typename T>
        void print(T value, std::string sep = ":", std::string end = "\n") {
            if constexpr (std::is_same_v<T, std::map<int, std::string>>) {
                for (auto const& [key, val] : value) {
                    std::cout << key << sep << " " << val << end;
                }
            }
            else if constexpr (std::is_same_v<T, std::vector<int>>) {
                for (auto const& val : value) {
                    std::cout << val << std::endl;
                }
            }

            else {
                std::cout << value << std::endl;
            }
            std::cout << value << std::endl;
        }


    }

    namespace string {
        inline bool is_lower(std::string const& str) {
            return std::ranges::all_of(str, [](const char c) -> bool { return std::islower(c); });
        }

        inline bool is_upper(std::string const& str) {
            // ai dont help
            return std::ranges::all_of(str, [](const char c) -> bool { return std::isupper(c); });
        }

    }

    namespace array {
        inline std::string join(std::vector<std::string> const& vec, std::string const& sep = "") {
            std::string result;
            // range-based for loop
            for (size_t i = 0; i < vec.size(); i++) {
                result.append(vec[i]);
                if (i != vec.size() - 1) {
                    result.append(sep);
                }
            }
            return result;
        }

    }

}

#endif
