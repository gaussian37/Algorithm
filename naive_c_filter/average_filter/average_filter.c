// https://gaussian37.github.io/autodrive-ose-average-filter/
int num_of_sample;
double prev_average;

double AvgFilter(double x){

    double average, alpha;

    // 샘플 수 +1 (+1 the number of sample)
    num_of_sample += 1;

    // 평균 필터의 alpha 값 (alpha of average filter)
    alpha = (num_of_sample - 1) / (num_of_sample + 0.0);

    // 평균 필터의 재귀식 (recursive expression of average filter)
    average = alpha * prev_average + (1 - alpha) * x;

    // 평균 필터의 이전 상태값 업데이트 (update previous state value of average filter)
    prev_average = average;

    return average;
}