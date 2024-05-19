
clean:
	bazel clean --expunge

unit-test:
	bazel test --test_output=all //cpp/lib/...:all

