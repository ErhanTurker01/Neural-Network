//
//  NeuralNetwork.cpp
//  Neural Network
//
//  Created by Erhan Türker on 11/2/24.
//

#include "NeuralNetwork.hpp"

Network::Network()
    : layers(), inputSize(0), outSize(0)
{
    
}
Network::Network(std::initializer_list<u_int> layerCounts){
    if (layerCounts.size() < 2)
        throw std::invalid_argument("Need at least two layers!");
    u_int prevCnt = 0;
    for(u_int count : layerCounts){
        if (count <= 0)
            throw std::invalid_argument("Layer size must be greater than 0!");
        
        if (prevCnt == 0){
            prevCnt = count;
            inputSize = count;
            continue;
        }
        layers.push_back(Layer(count, Neuron(prevCnt)));
        prevCnt = count;
    }
    outSize = prevCnt;
}

void Network::feedForward(const vector<float>& input){
    if (input.size() != inputSize)
        throw std::invalid_argument("Input size must be equal to input layer size!");
    for (u_int i = 0; i < inputSize; i++)
        layers[0][i].setActivation(input);
    for (u_int i = 1; i < layers.size(); i++) {
        Layer& layer = layers[i];
        Layer& prevLayer = layers[i-1];
        for (Neuron& n : layer)
            n.setActivation(prevLayer);
    }
}

float Network::cost(const vector<float>& answer) const{
    if (answer.size() != outSize)
        throw std::invalid_argument("Output size must be equal to answer size!");
    float cost = 0;
    for (u_int i = 0; i < outSize; i++) {
        const float& n = layers.back()[i].getActivation();
        const float& a = answer[i];
        cost += (n - a) * (n - a);
    }
    return cost / outSize;
};
