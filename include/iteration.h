#ifndef ITERATION_H
#define ITERATION_H

#include "block.h"
#include "key.h"
#include "shuffle.h"
#include <map>
#include <vector>

namespace Cascade {

class Reconciliation;

class Iteration
{
public:
    Iteration(Reconciliation& reconciliation, unsigned iteration_nr, bool biconf);
    ~Iteration();
    unsigned get_iteration_nr() const;
    const Key& get_shuffled_key() const;
    bool get_biconf() const;
    void reconcile();
private:
    void reconcile_cascade();
    void reconcile_biconf();
    Reconciliation& reconciliation;
    unsigned iteration_nr;
    bool biconf;
    size_t nr_key_bits;
    Shuffle shuffle;
    Key shuffled_key;
    std::vector<BlockPtr> top_blocks;
};

typedef std::shared_ptr<Iteration> IterationPtr;

} /* namespace Cascade */

#endif /* ifndef ITERATION_H */
