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
	int num_lay; //number of layers
	mat biases; // matrix of biases
	mat weights; // matrix of weights
public:
	Network(int *, int );
};

Network::Network (int *p, int lenght){
	int max;
	rowvec temp;

	temp.fill(-2.0);
	for (int i = 0; i < lenght; i++) { temp(i) = *(p + i); };
	max = temp.max;
	
	num_lay = lenght;
	biases.set_size(max, num_lay); // set size of matrix of biases
	weights.copy_size(biases); // same size as matrix of biases
	biases.fill(-2.0);
	weights.fill(-2.0);
	
	default_random_engine generator;
	normal_distribution<double> d(0.0, 1.0);
	int i,j;
	i = j = 0;
	for (; i < lenght; i++)
		for (; j < temp(i); j++) {
			biases(i, j) = d(generator);
			weights(i, j) = d(generator);
		};
};


int main()
{
	int prmt[3]{ 3 5 4 };
	Network net1(prmt, 3);
	return 0;
}

