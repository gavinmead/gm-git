load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "context_lib",
    srcs = [
        "builder.cpp",
        "context.cpp",
    ],
    hdrs = [
        "context.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//cpp/lib/cli/args:argtype_lib",
        "//cpp/lib/cli/command:command_lib",
        "//cpp/lib/cli/flags:flags_lib",
    ],
)

cc_test(
    name = "context_test",
    srcs = ["context_test.cpp"],
    visibility = ["//visibility:private"],
    deps = [
        ":context_lib",
        "//cpp/lib/cli/mocks:cli_mocks",
        "@com_google_googletest//:gtest_main",
    ],
)
