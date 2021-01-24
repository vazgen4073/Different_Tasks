#include <iostream>

int** rotateImage(int** a, int size)
{
    if (size <= 1) {
        return a;
    }

    int counter = 0, draw_counter = 0, temp_1, temp_2;
    temp_1 = a[0][0];
    int i = 0, j = 0, local_size, lc_counter = 0;
    local_size = size - lc_counter;

    while (lc_counter < size / 2) {

        if (counter == 0) {
            while (j < size - lc_counter) {
                temp_2 = a[i][j];
                a[i][j] = temp_1;
                temp_1 = temp_2;
                j++;
            }
            j--;
            i++;
        }
        if (counter == 1) {
            while (i < size - lc_counter) {
                temp_2 = a[i][j];
                a[i][j] = temp_1;
                temp_1 = temp_2;
                i++;
            }
            i--;
            j--;
        }
        if (counter == 2) {
            while (j >= lc_counter) {
                temp_2 = a[i][j];
                a[i][j] = temp_1;
                temp_1 = temp_2;
                j--;
            }
            j++;
            i--;
        }
        if (counter == 3) {
            while (i >= lc_counter) {
                temp_2 = a[i][j];
                a[i][j] = temp_1;
                temp_1 = temp_2;
                i--;
            };
            i++;

            local_size = size - lc_counter;
            counter = -1;
            draw_counter++;

            if (draw_counter == local_size - lc_counter - 1) {
                draw_counter = 0;
                lc_counter++;
                i = lc_counter;
                j = lc_counter;
            }
        }

        counter++;
    }

    return a;
}

int main()
{
    int n;
    std::cin >> n;
    int** vec = new int*[n];
    for (int i = 0; i < n; i++) {
        vec[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> vec[i][j];
        }
    }

    rotateImage(vec, n);

    for (int i = 0; i < n; i++) {
        delete[] vec[i];
    }
    delete[] vec;
}

