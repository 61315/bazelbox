load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def my_repositories():
    _maybe(
        http_archive,
        name = "com_google_glog",
        sha256 = "dfc074b41a5b86fc5dda4f0e2e2d6cc5b21f798c9fcc8ed5fea9c8f7c4613be6",
        strip_prefix = "glog-dd2b93d761a19860190cb3fa92066c8031e912e3",
        urls = [
            "https://mirror.bazel.build/github.com/google/glog/archive/dd2b93d761a19860190cb3fa92066c8031e912e3.tar.gz",
            "https://github.com/google/glog/archive/dd2b93d761a19860190cb3fa92066c8031e912e3.tar.gz",
        ],
    )

    _maybe(
        http_archive,
        name = "com_github_gflags_gflags",
        sha256 = "6e16c8bc91b1310a44f3965e616383dbda48f83e8c1eaa2370a215057b00cabe",
        strip_prefix = "gflags-77592648e3f3be87d6c7123eb81cbad75f9aef5a",
        urls = [
            "https://mirror.bazel.build/github.com/gflags/gflags/archive/77592648e3f3be87d6c7123eb81cbad75f9aef5a.tar.gz",
            "https://github.com/gflags/gflags/archive/77592648e3f3be87d6c7123eb81cbad75f9aef5a.tar.gz",
        ],
    )

    _maybe(
        http_archive,
        name = "org_ceres_solver_ceres_solver",
        build_file = "@ceres_practice//third_party:ceres.BUILD",
        sha256 = "ede5b4205ee8d7c7e029e9da74c7ee759fee6961f7e6bfa694274e4a55b8c7ca",
        strip_prefix = "ceres-solver-58c5edae2f7c4d2533fe8a975c1f5f0b892dfd3e",
        urls = [
            "https://mirror.bazel.build/github.com/ceres-solver/ceres-solver/archive/58c5edae2f7c4d2533fe8a975c1f5f0b892dfd3e.tar.gz",
            "https://github.com/ceres-solver/ceres-solver/archive/58c5edae2f7c4d2533fe8a975c1f5f0b892dfd3e.tar.gz",
        ],
    )

    _maybe(
        http_archive,
        name = "org_tuxfamily_eigen",
        build_file = "@ceres_practice//third_party:eigen.BUILD",
        sha256 = "ca7beac153d4059c02c8fc59816c82d54ea47fe58365e8aded4082ded0b820c4",
        strip_prefix = "eigen-eigen-f3a22f35b044",
        urls = [
            "http://mirror.bazel.build/bitbucket.org/eigen/eigen/get/f3a22f35b044.tar.gz",
            "https://bitbucket.org/eigen/eigen/get/f3a22f35b044.tar.gz",
        ],
    )

    _maybe(
        http_archive,
        name = "bazel_skylib",
        sha256 = "e5d90f0ec952883d56747b7604e2a15ee36e288bb556c3d0ed33e818a4d971f2",
        strip_prefix = "bazel-skylib-1.0.2",
        urls = ["https://github.com/bazelbuild/bazel-skylib/archive/1.0.2.tar.gz"],
    )

def _maybe(repo_rule, name, **kwargs):
    if name not in native.existing_rules():
        repo_rule(name = name, **kwargs)