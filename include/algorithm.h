#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>
#include <vector>

namespace Cascade {

class Algorithm
{
public:
    Algorithm(std::string name, 
              int nr_cascade_iterations,
              int (*block_size_function)(int iteration_nr, double estimated_bit_error_rate,
                                         unsigned long key_size),
              int nr_biconf_iterations,
              bool biconf_error_free_streak,
              bool biconf_correct_complement,
              bool biconf_cascade,
              bool ask_correct_parity_using_shuffle_seed,
              bool cache_shuffles);
    static Algorithm *get_by_name(std::string name);
    static std::vector<std::string> get_all_algorithm_names();
    std::string name;
    int nr_cascade_iterations;
    int (*block_size_function)(int iteration_nr, double estimated_bit_error_rate, unsigned long key_size);
    int nr_biconf_iterations;
    bool biconf_error_free_streak;
    bool biconf_correct_complement;
    bool biconf_cascade;
    bool ask_correct_parity_using_shuffle_seed;
    bool cache_shuffles;
};

} /* namespace Cascade */

#endif /* ifndef ALGORITHM_H */
