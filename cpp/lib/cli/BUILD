load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "cli_lib",
    srcs = [
        "arg_type.cpp",
        "command.cpp",
    ],
    hdrs = [
        "arg_type.h",
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

cc_test(
    name = "arg_type_test",
    srcs = ["arg_type_test.cpp"],
    deps = [
        ":cli_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
