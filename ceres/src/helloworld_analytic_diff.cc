#include "ceres/ceres.h"
#include "glog/logging.h"

class QuadraticCostFunction : public ceres::SizedCostFunction<1, 1> {
 public:
  virtual ~QuadraticCostFunction() {}
  virtual bool Evaluate(double const* const* parameters,
                        double* residuals,
                        double** jacobians) const {
    const double x = parameters[0][0];
    residuals[0] = 10 - x;

    if (jacobians != nullptr && jacobians[0] != nullptr) {
      jacobians[0][0] = -1;
    }
    return true;
  }
};

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);

  double x = 0.5;
  const double initial_x = x;

  ceres::Problem problem;

  ceres::CostFunction* cost_function = new QuadraticCostFunction;
  problem.AddResidualBlock(cost_function, nullptr, &x);

  ceres::Solver::Options options;
  options.minimizer_progress_to_stdout = true;
  ceres::Solver::Summary summary;
  ceres::Solve(options, &problem, &summary);

  std::cout << summary.BriefReport() << "\n";
  std::cout << "x : " << initial_x << " -> " << x << "\n";

  return 0;
}