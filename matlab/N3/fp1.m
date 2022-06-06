function g = fp1 (x)

g = (-2.3 .* sin(2.3 * x) .* (0.2 + x .^ 2) - (2 * x) .* cos(2.3 .* x)) ./ ((0.2 + x .^ 2) .^ 2);

endfunction
