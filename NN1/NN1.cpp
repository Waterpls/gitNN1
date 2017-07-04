// NN1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <armadillo>
#include <array>
#include <random>
#include <cmath>
// some comment
using namespace std;
using namespace arma;

rowvec sigmoid(rowvec z) {
	for (int i = 0; i < (int)z.size(); i++)
		z[i] = (1 / (1 + pow(2.718281828, -z[i])));
	return z;
};
vec sigmoid(vec z) {
	for (int i = 0; i < (int)z.size(); i++)
		z[i] = (1 / (1 + pow(2.718281828, -z[i])));
	return z;
};
double sigmoid(double z) { return z = (1 / (1 + pow(2.718281828, -z))); };


class Network {
public:
	int num_col; //number of layers
	int num_row; //number of colums
	vector<mat> weights;
	mat biases;
	
	vec feedforward(vec);
	int SGD(vector<vec> training_data, int epochs, int batch_size, double eta, bool test_data=false);
	Network(rowvec, int );
};

int Network::SGD(vector<vec> training_data, int epochs, int batch_size, double eta, bool test_data)
{
	return 0;
}

vec Network::feedforward(vec a)
{
	vec temp;
	for (int j = 0; j < num_col; j++) { //feedforward for network
		for (int i = 0; i < num_row; i++) // feedforward for column
			temp[i] = sigmoid(dot((weights[i+j*num_row].col(j)), a) + biases[i]);
		a = temp;
	};
		return a;
};

/* def SGD(self, training_data, epochs, mini_batch_size, eta,
            test_data=None):
        if test_data: n_test = len(test_data)
        n = len(training_data)
        for j in xrange(epochs):
            random.shuffle(training_data)
            mini_batches = [
                training_data[k:k+mini_batch_size]
                for k in xrange(0, n, mini_batch_size)]
            for mini_batch in mini_batches:
                self.update_mini_batch(mini_batch, eta)
            if test_data:
                print "Epoch {0}: {1} / {2}".format(
                    j, self.evaluate(test_data), n_test)
            else:
                print "Epoch {0} complete".format(j)*/



Network::Network (rowvec temp, int lenght){
	default_random_engine generator;
	normal_distribution<double> d(0.0, 1.0);
	
	num_row = (int) max(temp);
	num_col = lenght;
	mat temp_mat;
	temp_mat.set_size(num_row, num_col);
	mat biases(num_row,num_col);
	vector<mat> weights(num_row*num_col);
	temp_mat.imbue([&]() { return d(generator); });
	biases = temp_mat;
	for (int i = 0; i < (int) weights.size(); i++)
		weights[i] = temp_mat;
};


int main()
{
	rowvec sizes;
	sizes << 3 << 5 << 4 << endr;
	Network net1(sizes, 3);
	system("pause");
	return 0;
}

