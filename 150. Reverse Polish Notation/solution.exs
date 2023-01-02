defmodule Solution do
  def eval_helper(tokens, stack) do
    if length(tokens) > 0 do
      [head | tail] = tokens

      case head do
        "+" ->
          [a, b | stack_tail] = stack
          eval_helper(tail, [b + a | stack_tail])

        "-" ->
          [a, b | stack_tail] = stack
          eval_helper(tail, [b - a | stack_tail])

        "*" ->
          [a, b | stack_tail] = stack
          eval_helper(tail, [b * a | stack_tail])

        "/" ->
          [a, b | stack_tail] = stack
          eval_helper(tail, [div(b, a) | stack_tail])

        _ ->
          eval_helper(tail, [String.to_integer(head) | stack])
      end
    else
      [head | _] = stack
      head
    end
  end

  @spec eval_rpn(tokens :: [String.t()]) :: integer
  def eval_rpn(tokens) do
    eval_helper(tokens, [])
  end
end

defmodule TestCases do
  def assert(condition) do
    if condition do
      IO.puts("Test passed")
    else
      IO.puts("Test failed")
      # throw error with stack trace
      raise :test_failed

    end
  end

  def test do
    assert Solution.eval_rpn(["2", "1", "+", "3", "*"]) == 9
    assert Solution.eval_rpn(["4", "13", "5", "/", "+"]) == 6
    assert Solution.eval_rpn(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]) ==
             22
  end
end
