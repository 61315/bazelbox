cpp_file_names = glob(["*.cpp"])

[
    cc_binary(
        name = cpp_file_name.replace(".cpp", ""),
        srcs = [cpp_file_name],
        data = [
            "@my_raylib_project//:all_resources",
        ],
        deps = [
            "//:raylib",
        ],
    )
    for cpp_file_name in cpp_file_names
]

c_file_names = glob(["*.c"])

[
    cc_binary(
        name = c_file_name.replace(".c", ""),
        srcs = [c_file_name],
        copts = [
            "-DPLATFORM_DESKTOP",
        ],
        data = ["@my_raylib_project//:all_resources"],
        includes = [
            "rlights.h",
        ],
        deps = [
            "//:raylib",
        ],
    )
    for c_file_name in c_file_names
]
