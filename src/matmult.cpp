/**
 * Created by Herve Paulino
 * February 2024
 */


#include <cstdlib>
#include <iostream>
#include <cassert>

#include <cp/matrix.h>
#include <cp/timer.h>

using namespace std;
using namespace cp;

static constexpr auto default_size = 100;

string usage(char *program) {
    return string("usage: ") + program + " mat1_rows mat1_cols mat2_cols";
}

int main(int argc, char** argv) {

    if (argc == 1) {
        cout << "No matrix sizes given, assuming " << default_size << " x " << default_size << ".\n"
             << usage(argv[0]) << "\n";
    }
    else if (argc != 4) {
        cerr << usage(argv[0]);
        exit(1);
    }

    size_t mat1_rows = argc == 1 ? default_size : strtol(argv[1] , nullptr, 10);
    size_t mat1_cols = argc == 1 ? default_size : strtol(argv[2] , nullptr, 10);
    size_t mat2_cols = argc == 1 ? default_size : strtol(argv[3] , nullptr, 10);

    auto mat1 = make_matrix(mat1_rows, mat1_cols, 2);
    auto mat2 = make_matrix(mat1_cols, mat2_cols, 3);

    marrow::timer t;
    t.start();
    auto result = matrix_mult(mat1, mat2);
    t.stop();

    t.output_stats(cout);

    return 0;
}

