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
    
public:
    Network(std::initializer_list<u_int> layerCounts);
    void feedForward(const vector<float>& input);
};

#endif /* NeuralNetwork_hpp */
