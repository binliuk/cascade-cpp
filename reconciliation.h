#ifndef RECONCILIATION_H
#define RECONCILIATION_H

#include "key.h"
#include "iteration.h"
#include <map>
#include <queue>
#include <string>
#include <vector>

namespace Cascade {

class Algorithm;

class Reconciliation
{
public:
    Reconciliation(std::string algorithm_name,
                   const Key& noisy_key,
                   double estimated_bit_error_rate);
    ~Reconciliation();
    const Algorithm& get_algorithm(void) const;
    double get_estimated_bit_error_rate(void) const;
    Key& get_reconciled_key(void);
    void reconcile(void);
    void schedule_ask_correct_parity(BlockPtr block);
private:
    void service_all_pending_work(void);
    void service_pending_try_correct(void);
    void service_pending_ask_correct_parity(void);
    const Algorithm* algorithm;
    const Key& noisy_key;
    double estimated_bit_error_rate;
    Key reconciled_key;
    std::vector<IterationPtr> iterations;
    std::queue<BlockPtr> pending_ask_correct_parity_blocks;
    std::queue<BlockPtr> pending_try_correct_blocks;
};

} /* namespace Cascade */

#endif /* ifndef RECONCILIATION_H */
