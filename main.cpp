#include <iostream>

// Notes:
// - if value is not supposed to be modified in function we should use "const" to indicate it
// - int* a <=> int *a <=> int * a

// * (astrix symbol) - works for dereferencing the pointer - it means getting (or setting) the value pointed by pointer
int
ex_4_a(const int* a, const int* b){
    if(*a < *b) return *a;
    else return *b;
}

// Worth to note - if you want to return parameter (even without modifying) you don't need to mark param "const"
// If you do it, you'll need to cast it - return (int*)a
int*
ex_4_b(int* a, int* b) {
    if(*a < *b) return a;
    else return b;
}

// Basically writing (n) to the memory cell pointed by (w)
void
ex_5(int n, int* w){
    *w = n;
}

// Using pointers we always need to dereference with * to make operation on variable
// Using references (with &) - (b) becomes an alias(!) for passed variable so we don't need to dereference it
void
ex_6(int* a, int& b){
    int c = *a;
    *a = b;
    b = c;
}

// "new" keyword indicates "heap allocation" or "dynamic allocation"
// typically when you initialize the value it becomes destroyed once you leave the braces when it was defined
// variable allocated with "new" will not be destroyed until you tell it to do so
// you do it with "delete" keyword
// IMPORTANT RULE - For every "new" we have "delete"
// allocating with "new" always give you pointer - you can't access this memory directly
// also - when you use "new" allocation you don't need to specify type twice - use auto and write type only after "new"
double*
ex_7(){
    // double* x = new double(1.5);
    auto* x = new double(1.5);
    return x;
}

// in C programming language we would use malloc() function
// as an argument it takes the number of bytes we want to allocate
// it also returns the pointer (but of type void*) so to make it useful we need to cast it to our type
// we shouldn't use malloc() in C++ for two reasons:
//  - it's not type-safe (it returns void*)
//  - there is no way to initialize value during allocation (values are not even initialized to 0 - look calloc())
// even though it's good to know that malloc exists because "new" keyword uses it in the background to do it's work
// also - you cannot deallocate this memory with "delete" keyword - you need to use free()
double*
ex_7_malloc(){
    // double* x = (double*) malloc(sizeof(double));
    auto* x = (double*) malloc(sizeof(double));
    *x = 1.5;
    return x;
}

// size_t is equivalent to unsigned long
// I use it because it indicates it's size variable and it doesn't take negative values
double
ex_8(const double* x, const size_t size){
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += x[i];
    }
    sum /= (double) size;
    // Equivalent to sum = sum / (double)size;
    return sum;
}

double
ex_9(const double* x, const double* y, const size_t size){
    double z = 0.0;
    for (int i = 0; i < size; ++i) {
        z += (x[i] - y[i]) * (x[i] - y[i]);
    }
    return z;
}

int*
ex_10(size_t n){
    // Check if correct size to allocate
    if(n == 0) return nullptr;

    int* fibs = new int[n];

    // Check if small enough array
    if(n == 1) {
        fibs[0] = 0;
        return fibs;
    }

    // Finally do the task after assertions
    fibs[1] = 1;
    for (int i = 2; i < n; ++i) {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
    }
    return fibs;
}

double*
ex_11(const double* x, const double* y, size_t n){
    // Assertion again
    if(n == 0) return nullptr;
    auto* z = new double[n];
    for (int i = 0; i < n; ++i) {
        z[i] = x[i] + y[i];
    }
    return z;
}

int*
ex_16(int* x, size_t n, int* y, size_t m){
    if(n + m == 0) return nullptr;
    int* z = new int[n + m];
    // Assume n < m
    // if not than swap
    if(m < n){
        std::swap(x, y); // std::swap takes references to objects and swaps them
        std::swap(n, m);
    }

    // Use assumption to write to array
    for (int i = 0; i < n; ++i) {
        z[i] = x[i];
    }
    for (int i = 0; i < m; ++i) {
        z[i + n] = y[i];
    }
    return z;
}

int main() {
    // ALWAYS REMEMBER - HAVE "new"? HAVE "delete"!
    return 0;
}