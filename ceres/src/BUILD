cpp_file_names = glob(["*.cc"])

[
    cc_binary(
        name = cpp_file_name.replace(".cc", ""),
        srcs = [cpp_file_name],
        deps = [
            "@glog",
            "@org_ceres_solver_ceres_solver//:ceres",
        ],
    )
    for cpp_file_name in cpp_file_names
]
