load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_test")

cc_test(
    name = "assert_test",
    srcs = ["gtests.cc"],
    deps = [
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "my_math",
    srcs = ["my_math_test.cc"],
    deps = [
        "//cpp/lib:MyMathLib",
        "@com_google_googletest//:gtest_main",
    ],
)
