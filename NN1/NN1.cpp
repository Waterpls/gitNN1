// NN1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <armadillo>
#include <array>
#include <random>

using namespace std;
using namespace arma;

class Network {
	
public:
	int num_col; //number of layers
	int num_row; //number of colums
	vector<mat> weights;
	vector<mat> biases;
	
	Network(rowvec, int );
};

Network::Network (rowvec temp, int lenght){
	default_random_engine generator;
	normal_distribution<double> d(0.0, 1.0);
	
	num_row = (int) max(temp);
	num_col = lenght;
	mat temp_mat;
	temp_mat.set_size(num_row, num_col);
	vector<mat> biases(num_row*num_col);
	vector<mat> weights(num_row*num_col);
	temp_mat.imbue([&]() { return d(generator); });
	for (int i = 0; i < biases.size(); i++) {
		biases[i] = temp_mat;
		weights[i] = temp_mat;
	}
};

int main()
{
	rowvec sizes;
	sizes << 3 << 5 << 4 << endr;
	Network net1(sizes, 3);
	return 0;
}

