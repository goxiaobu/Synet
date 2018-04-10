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

#pragma once

#include "Synet/Common.h"
#include "Synet/Param.h"

namespace Synet
{
    template<typename Enum, int Size> SYNET_INLINE Enum StringToEnum(const String & string)
    {
        int type = Size - 1;
        for (; type >= 0; --type)
        {
            if (ValueToString<Enum>((Enum)type) == string)
                return (Enum)type;
        }
        return (Enum)type;
    }

    enum LayerType
    {
        LayerTypeUnknown = -1,
        LayerTypeAbs,
        LayerTypeBatchNorm,
        LayerTypeBias,
        LayerTypeConcat,
        LayerTypeConvolution,
        LayerTypeDropout,
        LayerTypeEltwise,
        LayerTypeExpandDims,
        LayerTypeFill,
        LayerTypeFlatten,
        LayerTypeInnerProduct,
        LayerTypeInput,
        LayerTypeLog,
        LayerTypeLrn,
        LayerTypeNormalize,
        LayerTypePermute,
        LayerTypePooling,
        LayerTypePriorBox,
        LayerTypeRegion,
        LayerTypeRelu,
        LayerTypeReorg,
        LayerTypeReshape,
        LayerTypeScale,
        LayerTypeSigmoid,
        LayerTypeSlice,
        LayerTypeSoftmax,
        LayerTypeSqueeze,
        LayerTypeTanh,
        LayerTypeSize
    };

    template<> SYNET_INLINE String ValueToString<LayerType>(const LayerType & value)
    {
        static const char * names[LayerTypeSize] =
        {
            "Abs",
            "BatchNorm",
            "Bias",
            "Concat",
            "Convolution",
            "Dropout",
            "Eltwise",
            "ExpandDims",
            "Fill",
            "Flatten",
            "InnerProduct",
            "Input",
            "Log",
            "LRN",
            "Normalize",
            "Permute",
            "Pooling",
            "PriorBox",
            "Region",
            "ReLU",
            "Reorg",
            "Reshape",
            "Scale",
            "Sigmoid",
            "Slice",
            "Softmax",
            "Squeeze",
            "Tanh",
        };
        return (value > LayerTypeUnknown && value < LayerTypeSize) ? names[value] : "";
    }

    template<> SYNET_INLINE void StringToValue<LayerType>(const String & string, LayerType & value)
    {
        value = StringToEnum<LayerType, LayerTypeSize>(string);
    }

    //-------------------------------------------------------------------------

    enum EltwiseOperationType
    {
        EltwiseOperationTypeUnknown = -1,
        EltwiseOperationTypeProduct,
        EltwiseOperationTypeSum,
        EltwiseOperationTypeMax,
        EltwiseOperationTypeSize
    };

    template<> SYNET_INLINE String ValueToString<EltwiseOperationType>(const EltwiseOperationType & value)
    {
        static const char * names[EltwiseOperationTypeSize] =
        {
            "Product",
            "Sum",
            "Max",
        };
        return (value > EltwiseOperationTypeUnknown && value < EltwiseOperationTypeSize) ? names[value] : "";
    }

    template<> SYNET_INLINE void StringToValue<EltwiseOperationType>(const String & string, EltwiseOperationType & value)
    {
        value = StringToEnum<EltwiseOperationType, EltwiseOperationTypeSize>(string);
    }

    //-------------------------------------------------------------------------

    enum NormRegionType
    {
        NormRegionTypeUnknown = -1,
        NormRegionTypeAcrossChannels,
        NormRegionTypeWithinChannel,
        NormRegionTypeSize
    };

    template<> SYNET_INLINE String ValueToString<NormRegionType>(const NormRegionType & value)
    {
        static const char * names[NormRegionTypeSize] =
        {
            "AcrossChannels",
            "WithinChannel",
        };
        return (value > NormRegionTypeUnknown && value < NormRegionTypeSize) ? names[value] : "";
    }

    template<> SYNET_INLINE void StringToValue<NormRegionType>(const String & string, NormRegionType & value)
    {
        value = StringToEnum<NormRegionType, NormRegionTypeSize>(string);
    }

    //-------------------------------------------------------------------------
    
    enum PoolingMethodType
    {
        PoolingMethodTypeUnknown = -1,
        PoolingMethodTypeMax,
        PoolingMethodTypeAverage,
        PoolingMethodTypeStochastic,
        PoolingMethodTypeSize
    };

    template<> SYNET_INLINE String ValueToString<PoolingMethodType>(const PoolingMethodType & value)
    {
        static const char * names[LayerTypeSize] =
        {
            "Max",
            "Average",
            "Stochastic",
        };
        return (value > PoolingMethodTypeUnknown && value < PoolingMethodTypeSize) ? names[value] : "";
    }

    template<> SYNET_INLINE void StringToValue<PoolingMethodType>(const String & string, PoolingMethodType & value)
    {
        value = StringToEnum<PoolingMethodType, PoolingMethodTypeSize>(string);
    }

    //-------------------------------------------------------------------------

    enum PriorBoxCodeType
    {
        PriorBoxCodeTypeUnknown = 0,
        PriorBoxCodeTypeCorner = 1,
        PriorBoxCodeTypeCenter = 2,
        PriorBoxCodeTypeCornerSize = 3,
        PriorBoxCodeTypeSize,
    };

    template<> SYNET_INLINE String ValueToString<PriorBoxCodeType>(const PriorBoxCodeType & value)
    {
        static const char * names[PriorBoxCodeTypeSize] =
        {
            "Corner",
            "Center",
            "CornerSize",
        };
        return (value > PriorBoxCodeTypeUnknown && value < PriorBoxCodeTypeSize) ? names[value] : "";
    }

    template<> SYNET_INLINE void StringToValue<PriorBoxCodeType>(const String & string, PriorBoxCodeType & value)
    {
        value = StringToEnum<PriorBoxCodeType, PriorBoxCodeTypeSize>(string);
    }

    //-------------------------------------------------------------------------

    struct ShapeParam
    {
        SYNET_PARAM_VALUE(Shape, dim, Shape());
    };

    struct BatchNormParam
    {
        SYNET_PARAM_VALUE(bool, useGlobalStats, true);
        SYNET_PARAM_VALUE(float, movingAverageFraction, 0.999f);
        SYNET_PARAM_VALUE(float, eps, 0.00001f);
    };

    struct BiasParam
    {
        SYNET_PARAM_VALUE(uint32_t, axis, 1);
        SYNET_PARAM_VALUE(uint32_t, numAxes, 1);
    };

    struct ConcatParam
    {
        SYNET_PARAM_VALUE(uint32_t, axis, 1);
    };

    struct ConvolutionParam
    {
        SYNET_PARAM_VALUE(uint32_t, outputNum, 0);
        SYNET_PARAM_VALUE(bool, biasTerm, true);
        SYNET_PARAM_VALUE(Shape, kernel, Shape());
        SYNET_PARAM_VALUE(Shape, pad, Shape());
        SYNET_PARAM_VALUE(Shape, stride, Shape());
        SYNET_PARAM_VALUE(Shape, dilation, Shape());
        SYNET_PARAM_VALUE(uint32_t, axis, 1);
        SYNET_PARAM_VALUE(uint32_t, group, 1);
    };

    struct ExpandDimsParam
    {
        SYNET_PARAM_VALUE(int32_t, axis, 0);
    };

    struct EltwiseParam
    {
        SYNET_PARAM_VALUE(EltwiseOperationType, operation, EltwiseOperationTypeSum);
        SYNET_PARAM_VALUE(Floats, coefficients, Floats());
    };

    struct FillParam
    {
        SYNET_PARAM_VALUE(float, value, 0.0f);
    }; 

    struct FlattenParam
    {
        SYNET_PARAM_VALUE(int32_t, axis, 1);
        SYNET_PARAM_VALUE(int32_t, endAxis, -1);
    };
    
    struct InnerProductParam
    {
        SYNET_PARAM_VALUE(uint32_t, outputNum, 0);
        SYNET_PARAM_VALUE(bool, biasTerm, true);
        SYNET_PARAM_VALUE(bool, transposeA, false);
        SYNET_PARAM_VALUE(bool, transposeB, false);
        SYNET_PARAM_VALUE(uint32_t, axis, 1);
    };

    struct InputParam
    {
        SYNET_PARAM_VECTOR(ShapeParam, shape);
    };

    struct LogParam
    {
        SYNET_PARAM_VALUE(float, base, -1.0f);
        SYNET_PARAM_VALUE(float, scale, 1.0f);
        SYNET_PARAM_VALUE(float, shift, 0.0f);
    };

    struct LrnParam
    {
        SYNET_PARAM_VALUE(uint32_t, localSize, 5);
        SYNET_PARAM_VALUE(float, alpha, 1.0f);
        SYNET_PARAM_VALUE(float, beta, 0.75f);
        SYNET_PARAM_VALUE(NormRegionType, normRegion, NormRegionTypeAcrossChannels);
        SYNET_PARAM_VALUE(float, k, 1.0f);
    };

    struct NormalizeParam
    {
        SYNET_PARAM_VALUE(bool, acrossSpatial, true);
        SYNET_PARAM_VALUE(bool, channelShared, true);
        SYNET_PARAM_VALUE(float, eps, 1e-10f);
    };

    struct PermuteParam
    {
        SYNET_PARAM_VALUE(Shape, order, Shape());
    };

    struct PoolingParam
    {
        SYNET_PARAM_VALUE(PoolingMethodType, method, PoolingMethodTypeUnknown);
        SYNET_PARAM_VALUE(Shape, kernel, Shape());
        SYNET_PARAM_VALUE(Shape, pad, Shape());
        SYNET_PARAM_VALUE(Shape, stride, Shape());
        SYNET_PARAM_VALUE(bool, globalPooling, false);
        SYNET_PARAM_VALUE(bool, yoloCompatible, false);
    };

    struct PriorBoxParam
    {
        SYNET_PARAM_VALUE(Floats, minSize, Floats());
        SYNET_PARAM_VALUE(Floats, maxSize, Floats());
        SYNET_PARAM_VALUE(Floats, aspectRatio, Floats());
        SYNET_PARAM_VALUE(bool, flip, true);
        SYNET_PARAM_VALUE(bool, clip, false);
        SYNET_PARAM_VALUE(Floats, variance, Floats());
        SYNET_PARAM_VALUE(Shape, imgSize, Shape());
        SYNET_PARAM_VALUE(Floats, step, Floats());
        SYNET_PARAM_VALUE(float, offset, 0.5f);
    };

    struct RegionParam
    {
        SYNET_PARAM_VALUE(uint32_t, coords, 4);
        SYNET_PARAM_VALUE(uint32_t, classes, 20);
        SYNET_PARAM_VALUE(uint32_t, num, 1);
        SYNET_PARAM_VALUE(bool, softmax, false);
        SYNET_PARAM_VALUE(Floats, anchors, Floats());
    };

    struct ReluParam
    {
        SYNET_PARAM_VALUE(float, negativeSlope, 0.0f);
    };

    struct ReorgParam
    {
        SYNET_PARAM_VALUE(bool, reverse, true);
        SYNET_PARAM_VALUE(uint32_t, stride, 1);
    };

    struct ReshapeParam
    {
        SYNET_PARAM_VALUE(Shape, shape, Shape());
        SYNET_PARAM_VALUE(int32_t, axis, 0);
        SYNET_PARAM_VALUE(int32_t, numAxes, -1);
    };

    struct ScaleParam
    {
        SYNET_PARAM_VALUE(uint32_t, axis, 1);
        SYNET_PARAM_VALUE(uint32_t, numAxes, 1);
        SYNET_PARAM_VALUE(bool, biasTerm, false);
    };

    struct SliceParam
    {
        SYNET_PARAM_VALUE(uint32_t, axis, 1);
        SYNET_PARAM_VALUE(Index, slicePoint, Index());
    };

    struct SoftmaxParam
    {
        SYNET_PARAM_VALUE(uint32_t, axis, 1);
    };

    struct LayerParam
    {
        SYNET_PARAM_VALUE(LayerType, type, LayerTypeUnknown);
        SYNET_PARAM_VALUE(String, name, String());
        SYNET_PARAM_VALUE(Strings, src, Strings());
        SYNET_PARAM_VALUE(Strings, dst, Strings());
        SYNET_PARAM_VECTOR(ShapeParam, weight);

        SYNET_PARAM_STRUCT(BatchNormParam, batchNorm);
        SYNET_PARAM_STRUCT(BiasParam, bias);
        SYNET_PARAM_STRUCT(ConcatParam, concat);
        SYNET_PARAM_STRUCT(ConvolutionParam, convolution);
        SYNET_PARAM_STRUCT(EltwiseParam, eltwise);
        SYNET_PARAM_STRUCT(ExpandDimsParam, expandDims);
        SYNET_PARAM_STRUCT(FillParam, fill);
        SYNET_PARAM_STRUCT(FlattenParam, flatten);
        SYNET_PARAM_STRUCT(InnerProductParam, innerProduct);
        SYNET_PARAM_STRUCT(InputParam, input);
        SYNET_PARAM_STRUCT(LogParam, log);
        SYNET_PARAM_STRUCT(LrnParam, lrn);
        SYNET_PARAM_STRUCT(NormalizeParam, normalize);
        SYNET_PARAM_STRUCT(PermuteParam, permute);
        SYNET_PARAM_STRUCT(PoolingParam, pooling);
        SYNET_PARAM_STRUCT(PriorBoxParam, priorBox);
        SYNET_PARAM_STRUCT(RegionParam, region);
        SYNET_PARAM_STRUCT(ReluParam, relu);
        SYNET_PARAM_STRUCT(ReorgParam, reorg);
        SYNET_PARAM_STRUCT(ReshapeParam, reshape);
        SYNET_PARAM_STRUCT(ScaleParam, scale);
        SYNET_PARAM_STRUCT(SliceParam, slice);
        SYNET_PARAM_STRUCT(SoftmaxParam, softmax);

        SYNET_PARAM_VALUE(Strings, debug, Strings());
    };

    struct NetworkParam
    {
        SYNET_PARAM_VALUE(String, name, String());
        SYNET_PARAM_VALUE(Strings, dst, Strings());
        SYNET_PARAM_VECTOR(LayerParam, layers);
    };

    SYNET_PARAM_HOLDER(NetworkParamHolder, NetworkParam, network);
}