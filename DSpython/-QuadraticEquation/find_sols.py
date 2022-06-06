from find_sols_function import find_sols
from Plot import build_plot

a = float(input())
b = float(input())
c = float(input())
sol = []

find_sols(a, b, c, sol)
print(sol)
build_plot(a, b, c, sol)