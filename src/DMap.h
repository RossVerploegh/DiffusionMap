//
//  DMap.h
//  DiffusionMap
//
//  Updated by Andrew Long on 08/18/17.
//  Copyright (c) 2016-2017 Andrew Long. All rights reserved.
//
//  Utilizes Armadillo (http://arma.sourceforge.net/) C++ LinAlg Library
//  Sanderson, C. Armadillo: An Open Source C++ Linear Algebra Library
//  for Fast Prototyping and Computationally Intensive Experiments.
//  Technical Report, NICTA, 2010.

#pragma once

#include "pyarma.h"
class DMap
{
public:
	DMap();
	void set_epsilon(double e);
	double get_epsilon() { return epsilon; }
	void set_num_evec(int n);
	int get_num_evec() { return num_evec; }
	int get_num_samples() { return N; }
	void set_dists(pyarr_d b);

	bool compute();
	
	pyarr_d get_evec_py();
	pyarr_d get_eval_py();
	arma::mat& get_evec();
	arma::vec& get_eval();
	void set_evec(pyarr_d evec);
	void set_eval(pyarr_d eval);
private:
	int N, num_evec;
	double epsilon;
	arma::mat eigenvec;
	arma::vec eigenval;
	arma::mat dists;
	arma::mat kernel;
	
	bool is_new_dist, is_new_kernel, is_new_solve;
	bool compute_kernel();
	bool compute_eigs();
};

