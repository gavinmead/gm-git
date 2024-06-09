load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "command_lib",
    srcs = [
        "command.cpp",
    ],
    hdrs = [
        "command.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//cpp/lib/cli/args:argtype_lib",
        "//cpp/lib/cli/flags:flags_lib",
    ],
)

cc_test(
    name = "command_test",
    srcs = ["command_test.cpp"],
    copts = [
        "-std=c++17",
    ],
    linkopts = [
        "-std=c++17",
    ],
    visibility = ["//visibility:private"],
    deps = [
        ":command_lib",
        "//cpp/lib/cli/mocks:cli_mocks",
        "@com_google_googletest//:gtest_main",
    ],
)
