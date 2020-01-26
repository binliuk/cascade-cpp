#ifndef BLOCK_H
#define BLOCK_H

#include <stddef.h>

class Key;

class Block
{
public:
    Block(Key& key, size_t start_bit_nr, size_t end_bit_nr);
    int compute_current_parity() const;
private:
    Key& key;
    size_t start_bit_nr;
    size_t end_bit_nr;
};

#endif /* ifndef BLOCK_H */
