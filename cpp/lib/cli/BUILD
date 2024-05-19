load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "cli_lib",
    srcs = ["add.cc"],
    hdrs = ["command.h"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "cli_test",
    srcs = ["cli_test.cc"],
    visibility = ["//visibility:private"],
    deps = [
        ":cli_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
