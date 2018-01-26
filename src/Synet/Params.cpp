/*
* Synet Framework (http://github.com/ermig1979/Synet).
*
* Copyright (c) 2018-2018 Yermalayeu Ihar.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include "Synet/Params.h"

namespace Synet
{
    struct LayerTypeName
    {
        LayerType type;
        String name;
    };

    const LayerTypeName g_layerTypeNames[] =
    {
        { LayerTypeInput, "Input" },
        { LayerTypeInnerProduct, "InnerProduct" },
        { LayerTypeRelu, "Relu" },
        { LayerTypeSigmoid, "Sigmoid" },
        { LayerTypePooling, "Pooling" },
        { LayerTypeConvolution, "Convolution" },
    };

    template<> String ValueToString<LayerType>(const LayerType & value)
    {
        if (value > LayerTypeUnknown && value < LayerTypeSize)
            return g_layerTypeNames[value].name;
        else
            return "";
    }

    template<> void StringToValue<LayerType>(const String & string, LayerType & value)
    {
        LayerType type = (LayerType)(LayerTypeSize - 1);
        for (; type > LayerTypeUnknown; type = (LayerType)((int)type - 1))
        {
            if (g_layerTypeNames[type].name == string)
            {
                value = type;
                break;
            }
        }
    }

    struct PoolingMethodTypeName
    {
        PoolingMethodType type;
        String name;
    };

    const PoolingMethodTypeName g_poolingMethodTypeNames[] =
    {
        { PoolingMethodTypeMax, "Max" },
        { PoolingMethodTypeAverage, "Average" },
        { PoolingMethodTypeStochastic, "Stochastic" },
    };

    template<> String ValueToString<PoolingMethodType>(const PoolingMethodType & value)
    {
        if (value > PoolingMethodTypeUnknown && value < PoolingMethodTypeSize)
            return g_poolingMethodTypeNames[value].name;
        else
            return "";
    }

    template<> void StringToValue<PoolingMethodType>(const String & string, PoolingMethodType & value)
    {
        PoolingMethodType type = (PoolingMethodType)(PoolingMethodTypeSize - 1);
        for (; type > PoolingMethodTypeUnknown; type = (PoolingMethodType)((int)type - 1))
        {
            if (g_poolingMethodTypeNames[type].name == string)
            {
                value = type;
                break;
            }
        }
    }
}