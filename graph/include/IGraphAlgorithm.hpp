#pragma once

#include "WeightGraph.hpp"

namespace gph
{
    class IGraphAlgorithm
    {
    public:
        void virtual Start(Graph) = 0;
    protected:
        virtual IGraphAlgorithm() = 0;
        virtual ~IGraphAlgorithm() = 0;
    };

    template<class T>
    class IWeightGraphAlgorithm : public IGraphAlgorithm
    {
    public:
        void virtual Start(WeightGraph<T>) = 0;
    protected:
        virtual IWeightGraphAlgorithm() = 0;
        virtual ~IWeightGraphAlgorithm() = 0;
    };
}