// Copyright (c) 2012-2019 The Lava Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef LAVA_BLOCKCACHE_H
#define LAVA_BLOCKCACHE_H

#include <primitives/block.h>

#include <vector>

class CBlockIndex;

class CBlockCache {
public:
    CBlockCache();
    ~CBlockCache() = default;

    void UpdateBestBlockIndex(const CBlockIndex* index);

    void AddBlock(const std::shared_ptr<const CBlock>& blk, std::function<bool()>const &func);

    void PushBlock();

private:
    std::vector<std::shared_ptr<CBlock> > blocks;
    const CBlockIndex* prevIndex;
    std::function<bool()> handle;
};

extern std::unique_ptr<CBlockCache> g_blockCache;
#endif // LAVA_BLOCKCACHE_H
