#include <thread>
#include <vector>
#include <ctime>
#include <cstring>
#include <iostream>
#include <time.h>
int n, n_threads;
int **A;
void mul (int *vec, int **res, int num_of_thread) {
    int i = num_of_thread;
    while (i < n) {
        int sum = 0;
        for (int j = 0; j < n; j++) {

            sum += A[i][j] * vec[j];
        }
        (*res)[i] = sum;
        i += n_threads;
    }
}


int main(int argc, char **argv)
{
    sscanf(argv[1], "%d", &n);
    sscanf(argv[2], "%d", &n_threads);
    A = new int*[n];
    int *vec = new int[n];
    int *res = new int[n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        for (int j = 0; j < n; j++) {
            A[i][j] = i;
        }
        vec[i] = 1;
        res[i] = 0;
    }
    struct timespec st1, st2;
    //unsigned int start_time = std::clock();
    clock_gettime(CLOCK_MONOTONIC, &st1);
    if (strcmp(argv[3], "0") == 0) {
        std::vector<std::thread> vec_of_threads;
        for (int i = 0; i < n_threads; i++) {
            vec_of_threads.emplace_back(std::thread(mul, vec, &res, i));
        }

        for (auto &z: vec_of_threads) {
            z.join();
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i] += A[i][j] * vec[j];
            }
        }
    }

    //unsigned int end_time = clock();
    std::clock_gettime(CLOCK_MONOTONIC, &st2);
    std::cout<<st2.tv_sec - st1.tv_sec<<std::endl;
    //std::cout<<((double)end_time - start_time)/CLOCKS_PER_SEC<<std::endl;

    delete[] res;
    delete[] vec;
    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A;
    return 0;
}
