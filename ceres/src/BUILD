[cc_binary(
    name = f.replace("\\", "/")[:-3],
    srcs = [f],
    deps = [
        "@org_ceres_solver_ceres_solver//:ceres",
        "@com_google_glog//:glog",
        ],
) for f in glob(
    ["**/*.cc"],
    exclude = ["**/lib/**"],
)]