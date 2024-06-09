load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "argtype_lib",
    srcs = [
        "arg_type.cpp",
    ],
    hdrs = [
        "arg_type.h",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "arg_type_test",
    srcs = ["arg_type_test.cpp"],
    deps = [
        ":argtype_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
