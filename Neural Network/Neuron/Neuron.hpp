//
//  Neuron.hpp
//  Neural Network
//
//  Created by Erhan Türker on 11/2/24.
//

#ifndef Neuron_hpp
#define Neuron_hpp
#include <vector>
#include <random>

class Neuron;

using std::vector;
using Weights = vector<float>;

class Neuron{
    float bias;
    Weights weights;
    float activation;
    
public:
    explicit Neuron(u_int con_size = 0);
    void setActivation(vector<float> activations);
    void setActivation(vector<Neuron> activations);
    float getActivation();
};

#endif /* Neuron_hpp */
