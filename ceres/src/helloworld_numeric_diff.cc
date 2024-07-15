#include "ceres/ceres.h"
#include "glog/logging.h"

struct NumericDiffCostFunctor {
    bool operator()(const double* const x, double* residual) const {
        residual[0] = 10.0 - x[0];
        return true;
    }
};

int main(int argc, char** argv) {
    google::InitGoogleLogging(argv[0]);

    double x = 0.5;
    const double initial_x = x;

    ceres::Problem problem;

    ceres::CostFunction* cost_function = 
    new ceres::NumericDiffCostFunction<NumericDiffCostFunctor, ceres::CENTRAL, 1, 1>(nullptr);

    problem.AddResidualBlock(cost_function, nullptr, &x);

    ceres::Solver::Options options;
    options.linear_solver_type = ceres::DENSE_QR;
    options.minimizer_progress_to_stdout = true;
    ceres::Solver::Summary summary;
    ceres::Solve(options, &problem, &summary);

    std::cout << summary.BriefReport() << "\n";
    std::cout << "x : " << initial_x
              << " -> " << x << "\n";

    return 0;
}