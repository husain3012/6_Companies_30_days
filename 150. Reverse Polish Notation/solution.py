

class Solution:
    def evalRPN(self, tokens) -> int:
        stack = []
        for token in tokens:
            if token == "+":
                a = stack.pop()
                b = stack.pop()
                stack.append(b+a)
            elif token == "-":
                a = stack.pop()
                b = stack.pop()
                stack.append(b-a)
            elif token == "*":
                a = stack.pop()
                b = stack.pop()
                stack.append(b*a)
            elif token == "/":
                a = stack.pop()
                b = stack.pop()
                stack.append(int(b/a))
            else:
                stack.append(int(token))
        return stack.pop()


class TestCases:
    def test(self, solution):
        assert solution.evalRPN(["2", "1", "+", "3", "*"]) == 9
        assert solution.evalRPN(["4", "13", "5", "/", "+"]) == 6
        assert solution.evalRPN(
            ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]) == 22
        print("All test cases passed!")


if __name__ == "__main__":
    test = TestCases()
    solution = Solution()
    test.test(solution)
