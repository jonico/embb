/*
 * Copyright (c) 2014-2016, Siemens AG. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef EMBB_CONTAINERS_INTERNAL_BLOCKING_QUEUE_INL_H_
#define EMBB_CONTAINERS_INTERNAL_BLOCKING_QUEUE_INL_H_


namespace embb {
namespace containers {

template <typename T>
void BlockingQueue<T>::SpecializedPush(const T& element) {
  internalQueue.push(element);
}

template <typename T>
void BlockingQueue<T>::SpecializedPop(T& element) {
  element = internalQueue.front();
  internalQueue.pop();
}

template <typename T>
bool BlockingQueue<T>::IsEmpty() {
  return internalQueue.empty();
}

template <typename T>
void BlockingQueue<T>::Enqueue(const T& element) {
  PushAndWakeUp(element);
}

template <typename T>
void BlockingQueue<T>::Dequeue(T& element) {
  BlockingPop(element);
}

}  // namespace containers
}  // namespace embb

#endif  // EMBB_CONTAINERS_INTERNAL_BLOCKING_QUEUE_INL_H_