
# filegroup(
#     name = "examples",
#     srcs = glob(["src/**/*.cpp"]),
# )

# [cc_binary(
#     name = f.replace("\\", "/")[:-3],
#     srcs = [f],
#     deps = [
#         "@org_ceres_solver_ceres_solver//:ceres",
#         "@com_google_glog//:glog",
#         ],
#     copts = [
#         "-std=c++17",
#     ]
# ) for f in glob(
#     ["**/*.cpp"],
#     exclude = ["**/lib/**"],
# )]