#ifndef SIGNAL_PROCESSOR_H
#define SIGNAL_PROCESSOR_H

#include <vector>
#include <iostream>
#include <mutex>

using namespace std;



/**
 * \brief    FIR for y[n] givemn input x and coefficients coeffs
 *           finite input response :  y[n] = k=0 -> M ∑​ c_k * x[n-k] (M is size of coefficients)
 */
template<typename T>
double apply_FIR(const vector<T> &x, const vector<T> &coeffs, size_t n)
{
	double output = 0.0;

	for (size_t k = 0; k < coeffs.size(); ++k)
	{
		output += coeffs[k] * x[n - k];
	}

	return output;
}



/**
 * \brief     Process vector input x with coefficients c.
 * \returns   Processed result vector y.  
 */
template<typename T>
vector<T> process_input_with_fir(const vector<T> &x, const vector<T> &c)
{
    vector<T> y(x.size());

    for (size_t k = 0; k < x.size(); ++k)
    {
        y[k] = apply_FIR(x, c, k);
    }

    return y;
}


/**
 * \brief    IIR for y[n] given input x (infinite input response)
 */
template<typename T>
double apply_IIR(const T &y_prev, const T &xn, const T alpha)
{
    return alpha * xn + (1 - alpha) * y_prev;
}


/**
 * \brief     Process vector input x with IIR.
 */
template<typename T>
vector<T> process_input_with_iir(const vector<T>& x, const T alpha)
{
    vector<T> y(x.size());

    if (x.empty()) return y;

    y[0] = x[0];
    
    for (size_t n = 1; n < x.size(); ++n)
    {
        y[n] = alpha * x[n] + (1 - alpha) * y[n - 1];
    }

    return y;
}



/**
 * HELPERS
 */

template<typename T>
void print_vector(const vector<T> &v)
{
    if (v.empty()) return;

	for (const auto &e: v)
	{
		cout << ' ' << e;
	}
	cout << endl;
}




#endif // SIGNAL_PROCESSOR_H
