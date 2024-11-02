//
//  main.cpp
//  Neural Network
//
//  Created by Erhan Türker on 11/2/24.
//

#include <iostream>
#include "Neuron/NeuralNetwork.hpp"

using std::cout, std::endl;

int main(int argc, const char * argv[]) {
    Network net = {5, 10, 3, 4, 1};
    net.feedForward({0, 0, 1, 0, 1});
    cout << net.cost({1}) << endl;
    return 0;
}
