cc_library(
    name = "raylib",
    srcs = select({
        "@platforms//os:macos": ["lib/libraylib.a"],
        "@platforms//os:windows": ["lib/raylib.lib"], # TODO: mingw support
        "@platforms//os:linux": ["lib/libraylib.a"],
    }),
    hdrs = glob(["include/*.h"]),
    includes = ["include"],
    linkopts = select({
        "@platforms//os:macos": [
            "-framework", "CoreVideo",
            "-framework", "IOKit",
            "-framework", "Cocoa",
            "-framework", "GLUT",
            "-framework", "OpenGL",
        ],
        "@platforms//os:windows": [
            "-DEFAULTLIB:gdi32.lib",
            "-DEFAULTLIB:opengl32.lib",
            "-DEFAULTLIB:user32.lib",
            "-DEFAULTLIB:winmm.lib",
            "-DEFAULTLIB:shell32.lib",
        ],
        "@platforms//os:linux": [
            "-lGL",
            "-lm",
            "-lpthread",
            "-ldl",
            "-lrt",
            "-lX11",
        ],
    }),
    visibility = ["//visibility:public"],
)