//
//  Neuron.cpp
//  Neural Network
//
//  Created by Erhan Türker on 11/2/24.
//

#include "Neuron.hpp"
#include <cmath>

static float sigmoid(float x) {
    return 1.0f / (1.0f + std::exp(-x));
}

static float genRn() {
    static std::random_device rd;
    static std::mt19937 generator(rd());
    static std::uniform_real_distribution<float> distribution(-1.0, 1.0);
    return distribution(generator);
}

Neuron::Neuron(u_int con_size)
    : weights(con_size)
{
    bias = genRn();
    activation = 0.0f;
    for (float& w : weights) {
        w = genRn();
    }
}

void Neuron::setActivation(vector<float> activations){
    activation = 0;
    for (u_int i = 0; i < activations.size(); i++) {
        const float& w = weights[i];
        const float& a = activations[i];
        activation += w * a;
    }
    activation += bias;
    activation = sigmoid(activation);
}

void Neuron::setActivation(vector<Neuron> activations){
    activation = 0;
    for (u_int i = 0; i < activations.size(); i++) {
        const float& w = weights[i];
        const float& a = activations[i].getActivation();
        activation += w * a;
    }
    activation += bias;
    activation = sigmoid(activation);
}

float Neuron::getActivation(){
    return activation;
}
