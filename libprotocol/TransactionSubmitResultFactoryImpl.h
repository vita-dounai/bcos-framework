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
 * @file TransactionSubmitResultFactoryImpl.h
 * @author: yujiechen
 * @date: 2021-05-08
 */
#pragma once
#include "../interfaces/protocol/TransactionSubmitResultFactory.h"
#include "TransactionSubmitResultImpl.h"

namespace bcos
{
namespace protocol
{
class TransactionSubmitResultFactoryImpl : public TransactionSubmitResultFactory
{
public:
    using Ptr = std::shared_ptr<TransactionSubmitResultFactoryImpl>;
    TransactionSubmitResultFactoryImpl() = default;
    ~TransactionSubmitResultFactoryImpl() override {}

    TransactionSubmitResult::Ptr createTxSubmitResult(
        bcos::crypto::HashType const& _txHash, int32_t _status) override
    {
        return std::make_shared<TransactionSubmitResultImpl>(_txHash, (TransactionStatus)_status);
    }

    TransactionSubmitResult::Ptr createTxSubmitResult(
        BlockHeader::Ptr _blockHeader, bcos::crypto::HashType const& _txHash) override
    {
        return std::make_shared<TransactionSubmitResultImpl>(_blockHeader, _txHash);
    }
};
}  // namespace protocol
}  // namespace bcos