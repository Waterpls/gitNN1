// NN1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <armadillo>
#include <array>
#include <random>
#include <cmath>

using namespace std;
using namespace arma;

/*    def feedforward(self, a):
        """Return the output of the network if "a" is input."""
        for b, w in zip(self.biases, self.weights):
            a = sigmoid(np.dot(w, a)+b)
        return a */

class Network {
public:
	int num_col; //number of layers
	int num_row; //number of colums
	vector<mat> weights;
	vector<mat> biases;
	
	mat feedforward(mat);
	Network(rowvec, int );
};

mat Network::feedforward(mat a)
{
	for (int i = 0; i < num_row; i++)
	{
		vec temp;
		//need rework of biases back to mat class instead of vector<mat>
		temp = sigmoid(dot(weights[i].col(i), a) + biases[i].col(i)(1));
		//a.col(i) = sigmoid( weights  );
	};
	return a;
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

rowvec sigmoid(rowvec z) {
	for (int i = 0; i < (int) z.size(); i++)
		z[i] = (1/(1+ pow(2.718281828, -z[i])));
	return z;
};
vec sigmoid(vec z) {
	for (int i = 0; i < (int) z.size(); i++)
		z[i] = (1 / (1 + pow(2.718281828, -z[i])));
	return z;
};
double sigmoid(double z) {return z = (1 / (1 + pow(2.718281828, -z)));};

int main()
{
	rowvec sizes;
	sizes << 3 << 5 << 4 << endr;
	Network net1(sizes, 3);
	system("pause");
	return 0;
}

