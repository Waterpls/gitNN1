// NN1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <armadillo>
#include <array>
#include <random>

using namespace std;
using namespace arma;

/*
class Network(object) :

	def __init__(self, sizes) :
	self.num_layers = len(sizes)
	self.sizes = sizes
	self.biases = [np.random.randn(y, 1) for y in sizes[1:]]
	self.weights = [np.random.randn(y, x)
	for x, y in zip(sizes[:-1], sizes[1:])]
*/
class Network {
	
public:
	int num_lay; //number of layers
	mat biases; // matrix of biases
	mat weights; // matrix of weights
	Network(rowvec, int );
};

Network::Network (rowvec temp, int lenght){
	int max_val;
	max_val = (int) max(temp);
	num_lay = lenght;
	biases.set_size(max_val, num_lay); // set size of matrix of biases
	weights.copy_size(biases); // same size as matrix of biases
	
	default_random_engine generator;
	normal_distribution<double> d(0.0, 1.0);
	biases.imbue([&]() { return d(generator); });
	weights.imbue([&]() { return d(generator); });
};


int main()
{
	rowvec sizes;
	sizes << 3 << 5 << 4 << endr;
	Network net1(sizes, 3);
	for (int i = 0; i < 3; i++)
		cout << net1.biases(i, 1) << '\n';
	return 0;
}

