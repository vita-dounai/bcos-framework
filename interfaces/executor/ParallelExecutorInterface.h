/*
 *  Copyright (C) 2021 FISCO BCOS.
 *  SPDX-License-Identifier: Apache-2.0
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 * @brief interface of Executor
 * @file ParallelExecutorInterface.h
 * @author: ancelmo
 * @date: 2021-07-27
 */

#pragma once

#include "../../libutilities/Common.h"
#include "../../libutilities/FixedBytes.h"
#include "../crypto/CommonType.h"
#include "../protocol/BlockHeader.h"
#include "../protocol/ExecutionParams.h"
#include "../protocol/ExecutionResult.h"
#include "../protocol/ProtocolTypeDef.h"
#include "../protocol/Transaction.h"
#include "../protocol/TransactionReceipt.h"
#include <memory>

namespace bcos
{
namespace executor
{
class ParallelExecutorInterface
{
public:
    using Ptr = std::shared_ptr<ParallelExecutorInterface>;
    using ConstPtr = std::shared_ptr<const ParallelExecutorInterface>;

    virtual void start(const bcos::protocol::BlockHeader::ConstPtr& blockHeader,
        std::function<void(const bcos::Error::ConstPtr&)> callback) noexcept = 0;

    virtual void executeTransaction(const std::string_view& to,
        const bcos::protocol::ExecutionParams::ConstPtr& input,
        std::function<void(const bcos::Error::ConstPtr&, bcos::protocol::ExecutionResult::Ptr&&)>
            callback) noexcept = 0;

    // Write data to storage, return all contract's change hash
    virtual void commit(bcos::protocol::BlockNumber blockNumber,
        std::function<const bcos::Error::ConstPtr&> callback) noexcept = 0;

    // drop current changes
    virtual void rollback(bcos::protocol::BlockNumber blockNumber,
        std::function<void(const bcos::Error::ConstPtr&)> callback) noexcept = 0;

    // drop all status
    virtual void reset(std::function<void(const bcos::Error::ConstPtr&)>) noexcept = 0;
};
}  // namespace executor
}  // namespace bcos
