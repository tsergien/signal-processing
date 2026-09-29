#include <iostream>
#include <fstream>
#include <sstream>
#include "signal_processor.h"

vector<double> read_csv(const string& filename)
{
    ifstream file(filename);

    vector<double> values;
    string line;

    // Skip header
    getline(file, line);

    while (getline(file, line))
    {
        stringstream ss(line);

        string sample;
        string value;

        getline(ss, sample, ',');
        getline(ss, value, ',');

        values.push_back(stod(value));
    }

    return values;
}

int main(int argc, char **argv)
{
    /**
     * Simple tests
     */
    {
        vector<double> input{};
    
        for (int j = 1; j < argc; ++j)
        {
            input.push_back( stod(argv[j]) );
        }
        print_vector(input);
    
        const vector<double> coeffs{0.4, 0.5, 0.6};
    
        auto y = process_input_with_fir(input, coeffs);
        print_vector(y);
    
        auto y2 = process_input_with_iir(input, 0.5);
        print_vector(y2);
    }

    /**
     * File tests
     */
    {
        vector<double> input = read_csv("data/input.csv");

        const vector<double> coeffs{0.1, 0.2, 0.7};
        auto output = process_input_with_fir(input, coeffs);
        
        ofstream output_file("data/output_fir.csv");
        output_file << "sample,value" << '\n';
        size_t k = 0;
        for (double value : output)
            output_file << k++ << "," << value << '\n';

        output_file.close();


        auto output_iir = process_input_with_iir(input, 0.5);
        output_file.open("data/output_iir.csv");
        output_file << "sample,value" << '\n';
        k = 0;
        for (double value : output_iir)
            output_file << k++ << "," << value << '\n';
        output_file.close();

    }

    return 0;
}
