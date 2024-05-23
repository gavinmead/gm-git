load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "cli_lib",
    srcs = [
        "command.cpp",
        "flag.cpp",
    ],
    hdrs = [
        "command.h",
        "flag.h",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "flag_lib",
    srcs = [
        "flag.cpp",
    ],
    hdrs = [
        "flag.h",
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

cc_test(
    name = "flag_test",
    srcs = ["flag_test.cpp"],
    visibility = ["//visibility:private"],
    deps = [
        ":cli_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
