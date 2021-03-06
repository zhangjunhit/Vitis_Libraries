/*
 * Copyright 2019 Xilinx, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _XF_GRAPH_SPARSE_SIMILARITY_KERNEL_HPP_
#define _XF_GRAPH_SPARSE_SIMILARITY_KERNEL_HPP_

#include "similarity/sparse_similarity.hpp"
#include "similarity/sort_top_k.hpp"
#include "similarity/enums.hpp"

#include <ap_int.h>
#include <hls_math.h>
#include <hls_stream.h>

#define W_DATA 32
#define CHANNEL_NUMBER 4
#define PU_NUMBER 8
#define RAM_SIZE 15
#define MAX_K 33
#define EXT_MEM_SZ 32 << 10

template <typename I, typename F>
inline F bitsToF(I in) {
    union {
        I __I;
        F __F;
    } __T;
    __T.__I = in;
    return __T.__F;
}

template <typename F, typename I>
inline I fToBits(F in) {
    union {
        I __I;
        F __F;
    } __T;
    __T.__F = in;
    return __T.__I;
}

template <typename T>
struct is_float {
    operator bool() { return false; }
};

template <>
struct is_float<float> {
    operator bool() { return true; }
};

void sparseSimilarityKernel(ap_uint<32>* config,
                            ap_uint<32>* sourceIndice,
                            ap_uint<32>* sourceWeight,

                            ap_uint<32 * CHANNEL_NUMBER>* offsetCSR0,
                            ap_uint<32 * CHANNEL_NUMBER>* indexCSR0,
                            ap_uint<32 * CHANNEL_NUMBER>* weight0,

                            ap_uint<32 * CHANNEL_NUMBER>* offsetCSR1,
                            ap_uint<32 * CHANNEL_NUMBER>* indexCSR1,
                            ap_uint<32 * CHANNEL_NUMBER>* weight1,

                            ap_uint<32 * CHANNEL_NUMBER>* offsetCSR2,
                            ap_uint<32 * CHANNEL_NUMBER>* indexCSR2,
                            ap_uint<32 * CHANNEL_NUMBER>* weight2,

                            ap_uint<32 * CHANNEL_NUMBER>* offsetCSR3,
                            ap_uint<32 * CHANNEL_NUMBER>* indexCSR3,
                            ap_uint<32 * CHANNEL_NUMBER>* weight3,

                            ap_uint<32 * CHANNEL_NUMBER>* offsetCSR4,
                            ap_uint<32 * CHANNEL_NUMBER>* indexCSR4,
                            ap_uint<32 * CHANNEL_NUMBER>* weight4,

                            ap_uint<32 * CHANNEL_NUMBER>* offsetCSR5,
                            ap_uint<32 * CHANNEL_NUMBER>* indexCSR5,
                            ap_uint<32 * CHANNEL_NUMBER>* weight5,

                            ap_uint<32 * CHANNEL_NUMBER>* offsetCSR6,
                            ap_uint<32 * CHANNEL_NUMBER>* indexCSR6,
                            ap_uint<32 * CHANNEL_NUMBER>* weight6,

                            ap_uint<32 * CHANNEL_NUMBER>* offsetCSR7,
                            ap_uint<32 * CHANNEL_NUMBER>* indexCSR7,
                            ap_uint<32 * CHANNEL_NUMBER>* weight7,

                            ap_uint<32>* resultID,
                            float* similarity);
#endif
