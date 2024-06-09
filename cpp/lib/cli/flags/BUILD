load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "flags_lib",
    srcs = [
        "flag.cpp",
    ],
    hdrs = [
        "flag.h",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "flag_test",
    srcs = ["flag_test.cpp"],
    deps = [
        ":flags_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
