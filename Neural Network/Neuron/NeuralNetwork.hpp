//
//  NeuralNetwork.hpp
//  Neural Network
//
//  Created by Erhan Türker on 11/2/24.
//

#ifndef NeuralNetwork_hpp
#define NeuralNetwork_hpp
#include "Neuron.hpp"

using Layer = vector<Neuron>;

class Network{
    vector<Layer> layers;
    u_int inputSize;
    u_int outSize;
    
public:
    Network(std::initializer_list<u_int> layerCounts);
    Network();
    void feedForward(const vector<float>& input);
    virtual float cost(const vector<float>& answer) const;
};

#endif /* NeuralNetwork_hpp */
