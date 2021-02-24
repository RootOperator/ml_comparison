#include "knn.hpp"
#include <cmath>
#include <limits>
#include "map"
#include "stdint.h"
#include "data_handler.hpp"


knn::knn(int val) {
    k = val
}

knn::knn() {

}

knn::~knn() {

}

void knn::find_knearest(data *query_point) {
    neigbours = new std::vector<data *>;
    double min = std::numeric_limits<double>::max();
    double previous_min = min;
    int index = 0;
    for (int i = 0; i < k; ++i) {
        if (i == 0) {
            for (int j = 0; j < training_data->size(); ++j) {
                double distance = calculate_distance(query_point, training_data->at(j));
                training_data->at(j)->set_distance(distance);
                if (distance < min) {
                    min = distance;
                    index = j;
                }
            }
            neighbours->push_back(training_data->at(index));
            previous_min = min;
            min = std::numeric_limits<double>::max();
        } else {
            for (int j = 0; j < training_data->size(); ++j) {
                double distance = calculate_distance(query_point, training_data->at(j));
                if (distance > previous_min && distance < min) {
                    min = distance;
                    index = j;
                }
            }
            neighbours->push_back(training_data->at(index));
            previous_min = min;
            min = std::numeric_limits<double>::max();
        }
    }
}

void knn::set_training_data(std::vector<data *> *vect) {
    training_data = vect;
}

void knn::set_test_data(std::vector<data *> *vect) {
    test_data = vect;
}

void knn::set_validation_data(std::vector<data *> *vect) {
    validation_data = vect;
}

void knn::set_k(int val) {
    k = val;
}

int knn::predict();

double knn::calculate_distance(data *query_point, data *input) {
    double distance = 0.0;
    if (query_point->get_feature_vector_size() != input->get_feature_vector_size()) {
        printf("Error vector size mismatch.\n");
        exit(1)
    }
#ifdef EUCLID
    for (unsigned i = 0; 1 < query_point->get_feature_vector_size(); ++1 ){
        distance = pow(query_point->get_feature_vector()->at(i) - input->get_feature_vector()->at(i), 2);
    }
    distance = sqrt(distance);
#elif defined MANHATTEN
#endif
    return distance;
}

double knn::validate_performance();

double knn::test_performance();