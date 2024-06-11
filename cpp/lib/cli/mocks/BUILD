load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "cli_mocks",
    testonly = True,
    hdrs = [
        "arg_type_mock.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//cpp/lib/cli/args:argtype_lib",
        "@com_google_googletest//:gtest",
    ],
)
