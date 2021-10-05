// TestNormal.cpp
//
// First program test the Boost statistics library.
//
// Look at the Normal distribution because it is important.
// And gamma distribution
//
// 2008-6-27 DD initial code
// 2011-11-9 DD for QN course
//
// (C) Datasim Education BV 2009-2011
//

#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/gamma.hpp>
#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/poisson.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions

#include <vector>
#include <iostream>
using namespace std;


int main()
{
	// Don't forget to tell compiler which namespace
	using namespace boost::math;

	double scaleParameter = 0.5;
	exponential_distribution<> myExponential(scaleParameter);

	// Distributional properties
	double x = 10.25;

	cout.precision(10); // Setting the precision for cout

	cout << "\n***exponential distribution: \n";
	cout << "pdf: " << pdf(myExponential, x) << endl;
	cout << "cdf: " << cdf(myExponential, x) << endl;
	cout << "cdf complement: " << cdf(complement(myExponential, x)) << endl;
	cout << "Quantile:(.7) " << quantile(myExponential, 0.7) << endl;
	cout << "Quantile complement: " << quantile(complement(myExponential, 0.7)) << endl;
	cout << "Mean: " << mean(myExponential) << endl;
	cout << "Variance: " << variance(myExponential) << endl;
	cout << "Median: " << median(myExponential) << endl;
	cout << "Standard deviation: " << standard_deviation(myExponential) << endl;
	cout << "Skewness: " << skewness(myExponential) << endl;
	cout << "Mode: " << mode(myExponential) << endl;
	cout << "Kurtosis excess: " << kurtosis_excess(myExponential) << endl;
	cout << "Kurtosis: " << kurtosis(myExponential) << endl;
	cout << "Characteristic function: " << chf(myExponential, x) << endl;
	cout << "Hazard: " << hazard(myExponential, x) << endl;
	

	// Poisson distribution:
	double lambda = 3.0; // lambda
	poisson_distribution<double> myPoisson(lambda);

	double val = 13.0;

	// https://www.boost.org/doc/libs/1_35_0/libs/math/doc/sf_and_dist/html/math_toolkit/dist/dist_ref/dists/poisson_dist.html

	cout << "\n***poisson distribution: \n";
	cout << "pdf: " << pdf(myPoisson, x) << endl;
	cout << "cdf: " << cdf(myPoisson, x) << endl;
	cout << "cdf complement: " << cdf(complement(myPoisson, x)) << endl;
	cout << "Quantile: (.7)" << quantile(myPoisson, 0.7) << endl;
	cout << "Quantile complement: " << quantile(complement(myPoisson, 0.7)) << endl;
	cout << "Mean: " << mean(myPoisson) << endl;
	cout << "Variance: " << variance(myPoisson) << endl;
	cout << "Median: " << median(myPoisson) << endl;
	cout << "Standard deviation: " << standard_deviation(myPoisson) << endl;
	cout << "Skewness: " << skewness(myPoisson) << endl;
	cout << "Mode: " << mode(myPoisson) << endl;
	cout << "Kurtosis excess: " << kurtosis_excess(myPoisson) << endl;
	cout << "Kurtosis: " << kurtosis(myPoisson) << endl;
	cout << "Characteristic function: " << chf(myPoisson, x) << endl;
	cout << "Hazard: " << hazard(myPoisson, x) << endl;

	vector<double> pdfList;
	vector<double> cdfList;

	double start = 0.0;
	double end = 10.0;
	long N = 30;		// Number of subdivisions

	val = 0.0;
	double h = (end - start) / double(N);

	for (long j = 1; j <= N; ++j)
	{
		pdfList.push_back(pdf(myPoisson, val));
		cdfList.push_back(cdf(myPoisson, val));

		val += h;
	}

	for (long j = 0; j < pdfList.size(); ++j)
	{
		cout << pdfList[j] << ", ";

	}

	cout << "***" << endl;

	for (long j = 0; j < cdfList.size(); ++j)
	{
		cout << cdfList[j] << ", ";

	}

	return 0;
}