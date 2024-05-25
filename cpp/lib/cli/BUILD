load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "cli_lib",
    srcs = [
        "command.cpp",
    ],
    hdrs = [
        "command.h",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "command_test",
    srcs = ["command_test.cpp"],
    visibility = ["//visibility:private"],
    deps = [
        ":cli_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
