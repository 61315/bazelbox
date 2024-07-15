alias(
    name = "raylib",
    actual = select({
        "@platforms//os:windows": "@raylib_windows//:raylib",
        "@platforms//os:macos": "@raylib_macos//:raylib",
        "@platforms//os:linux": "@raylib_linux//:raylib",
    }),
    visibility = ["//visibility:public"],
)

filegroup(
    name = "all_resources",
    srcs = glob(["resources/**"]),
    visibility = ["//visibility:public"],
)