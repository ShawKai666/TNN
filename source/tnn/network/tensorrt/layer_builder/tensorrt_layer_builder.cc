// Tencent is pleased to support the open source community by making TNN available.
//
// Copyright (C) 2020 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#include "tnn/network/tensorrt/layer_builder/tensorrt_layer_builder.h"

namespace TNN_NS {

TensorRTLayerBuilder::TensorRTLayerBuilder(LayerType type) : TensorRTBaseLayerBuilder(type) {
    is_plugin = false;
}

TensorRTLayerBuilder::~TensorRTLayerBuilder() {
}

Status TensorRTLayerBuilder::Init(Context* context, LayerParam* param, LayerResource* resource, std::vector<Blob*>& input_blobs,
        std::vector<Blob*>& output_blobs, AbstractDevice* device) {
    auto tmp_device = GetDevice(DEVICE_NAIVE);
    if (tmp_device == nullptr) printf("11111111\n");
    auto tmp_context = tmp_device->CreateContext(0);
    if (tmp_context == nullptr) printf("2222222\n");
    Status ret = m_layer->Init(tmp_context, param, resource, input_blobs, output_blobs, tmp_device);
    if (ret != TNN_OK) {
        return ret;
    }

    input_blobs_  = m_layer->GetInputBlobs();
    output_blobs_ = m_layer->GetOutputBlobs();

    param_    = param;
    resource_ = resource;

    return TNN_OK;
}

Status TensorRTLayerBuilder::Reshape() {
    return TNN_OK;
}

Status TensorRTLayerBuilder::Forward() {
    return TNN_OK;
}

}  //  namespace TNN_NS
