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
        }


    }

    namespace string {
        inline bool is_lower(std::string const& str) {
            return std::ranges::all_of(str, [](const char c) -> bool { return std::islower(c); });
        }

        inline bool is_upper(std::string const& str) {
            return std::ranges::all_of(str, [](const char c) -> bool { return std::isupper(c); });
        }

    }

    namespace array {
        inline std::string join(std::vector<std::string> const& vec, std::string const& sep = "") {
            std::string result;
            for (size_t i = 0; i < vec.size(); i++) {
                result.append(vec[i]);
                if (i != vec.size() - 1) {
                    result.append(sep);
                }
            }
            return result;
        }

        inline std::vector<int> qsort(std::vector<int> const& vec) { // NOLINT
            if (vec.size() <= 1) {
                return vec;
            }
            else {
                int pivot = vec[0];
                std::vector<int> less;
                std::vector<int> greater;
                for (size_t i = 1; i < vec.size(); i++) {
                    if (vec[i] <= pivot) {
                        less.push_back(vec[i]);
                    }
                    else {
                        greater.push_back(vec[i]);
                    }
                }
                std::vector<int> result = qsort(less);
                result.push_back(pivot);
                std::vector<int> greaterSorted = qsort(greater);
                result.insert(result.end(), greaterSorted.begin(), greaterSorted.end());
                return result;
            }
        }

        inline std::vector<int> binary_search(std::vector<int> const& vec, int const& target) {
            int left = 0;
            int right = vec.size() - 1;
            while (left <= right) {
                if (int mid = left + (right - left) / 2; vec[mid] == target) {
                    return { mid };
                }
                else if (vec[mid] < target) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            return { -1 };
        }
    }


    // standalone functions
    inline std::vector<int> range(int start, int end, int step = 1) {
        std::vector<int> result;
        for (int i = start; i < end; i += step) {
            result.push_back(i);
        }
        return result;
    }

    inline std::vector<long int> range(long int start, long int end, long int step = 1) {
        std::vector<long int> result;
        for (long int i = start; i < end; i += step) {
            result.push_back(i);
        }
        return result;
    }

    inline std::vector<long long int> range(long long int start, long long int end, long long int step = 1) {
        std::vector<long long int> result;
        for (long long int i = start; i < end; i += step) {
            result.push_back(i);
        }
        return result;
    }

}

#endif
