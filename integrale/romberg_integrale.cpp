std::vector<std::vector<double>> rombergIntegral(double a, double b, size_t n, const std::function<double (double)> &f) {
    std::vector<std::vector<double>> romberg_integral(n, std::vector<double>(n));

    romberg_integral.front().front() = trapezoidalIntegral(a, b, 1, f);

    double h = b-a;
    for(size_t step = 1; step < n; step++) {
        h *= 0.5;

        double trapezoidal_integration = 0;
        size_t stepEnd = pow(2, step - 1);
        for(size_t tzStep = 1; tzStep <= stepEnd; tzStep++) {
            const double deltaX = (2*tzStep - 1)*h;
            trapezoidal_integration += f(a + deltaX);
        }
        romberg_integral[step].front() = 0.5*romberg_integral[step - 1].front() + trapezoidal_integration*h;

        for(size_t rbStep = 1; rbStep <= step; rbStep++) {
            const double k = pow(4, rbStep);
            romberg_integral[step][rbStep] = (k*romberg_integral[step][rbStep-1] - romberg_integral[step-1][rbStep-1])/(k-1);
        }
    }

    return romberg_integral;
}